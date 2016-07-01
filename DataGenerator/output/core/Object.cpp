#include "Object.h"

#define KEY int2String(r->id)

namespace tables
{
	Object::Object(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Object_table *r = new Object_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true);
			r->type = atoi(carrier.GetField(i, 2, "type").c_str());
			r->value = atoi(carrier.GetField(i, 3, "value").c_str());
			r->res = carrier.GetField(i, 4, "res", true);

			m_data[KEY] = *r;
		}
	}

	Object::~Object(void)
	{

	}

	Object_table* Object::getObjectVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Object::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Object::fileName()
	{
		return "Object.csv";
	}
}
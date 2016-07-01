#include "Drop_item.h"

#define KEY int2String(r->id)

namespace tables
{
	Drop_item::Drop_item(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Drop_item_table *r = new Drop_item_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->item_id = carrier.GetField(i, 1, "item_id", true);
			r->weight = carrier.GetField(i, 2, "weight", true);

			m_data[KEY] = *r;
		}
	}

	Drop_item::~Drop_item(void)
	{

	}

	Drop_item_table* Drop_item::getDrop_itemVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Drop_item::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Drop_item::fileName()
	{
		return "Drop_item.csv";
	}
}
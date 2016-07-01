#include "Elf.h"

#define KEY int2String(r->id)

namespace tables
{
	Elf::Elf(unsigned const char* data, size_t size)
	{
		InterDataCarrier carrier(data, size, fileName());
		Error = carrier.Error;
		if (!Error.empty())
		{
			return;
		}

		for (size_t i = 0; i < carrier.GetRecordCount(); i++)
		{
			Elf_table *r = new Elf_table();
			r->id = atoi(carrier.GetField(i, 0, "id").c_str());
			r->name = carrier.GetField(i, 1, "name", true);
			r->hp = atoi(carrier.GetField(i, 2, "hp").c_str());
			r->attack = atoi(carrier.GetField(i, 3, "attack").c_str());
			r->velocity = atof(carrier.GetField(i, 4, "velocity").c_str());
			r->character_in = carrier.GetField(i, 5, "character_in", true);

			m_data[KEY] = *r;
		}
	}

	Elf::~Elf(void)
	{

	}

	Elf_table* Elf::getElfVo(int id)
	{
		auto it = m_data.find(int2String(id));
		if (it == m_data.end())
		{
			return nullptr;
		} else {
			return &((*it).second);
		}
	}

	std::string Elf::int2String(int num)
	{
		std::stringstream ss;
		std::string str;
		ss<<num;
		ss>>str;
		return str;
	}

	const char* Elf::fileName()
	{
		return "Elf.csv";
	}
}
#ifndef __TABLES_Stage_H__
#define __TABLES_Stage_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Stage_table 
	{
	public:
		//id
		int id;
		//数据
		std::string data;
		Stage_table()
		{
			
		}
	};

	class Stage
	{
	public:
		Stage(unsigned const char* data, size_t size);
		~Stage(void);
		std::map<std::string, Stage_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Stage_table* getStageVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Stage_H__

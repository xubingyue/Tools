#ifndef __TABLES_Monster_H__
#define __TABLES_Monster_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class Monster_table 
	{
	public:
		//id
		int id;
		//名字
		std::string name;
		//掉落id
		int diropId;
		//血量
		int hp;
		//攻击力
		int attack;
		//速度
		float velocity;
		//形象
		std::string character_in;
		//场景地图序号
		int sceneID;
		//玩家等级下限
		int minLevel;
		//玩家等级上限
		int maxLevel;
		//副本序号
		int raidID;
		//副本怪点
		int monsterPoint;
		Monster_table()
		{
			
		}
	};

	class Monster
	{
	public:
		Monster(unsigned const char* data, size_t size);
		~Monster(void);
		std::map<std::string, Monster_table> m_data;
		static const char* fileName();
		std::string Error;
		
		Monster_table* getMonsterVo(int id);
		std::string int2String(int num);
	};
}

#endif  // __TABLES_Monster_H__

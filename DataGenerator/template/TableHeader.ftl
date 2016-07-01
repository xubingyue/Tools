#ifndef __TABLES_${className}_H__
#define __TABLES_${className}_H__
#include "cocos2d.h"
#include "../../core/data/database/TableHelper.h"

USING_NS_CC;

namespace tables
{
	class ${className}_table 
	{
	public:
		<#list messages as message>
		//${message.comment}
		${message.attributeType} ${message.name};
		</#list>
		${className}_table()
		{
			
		}
	};

	class ${className}
	{
	public:
		${className}(unsigned const char* data, size_t size);
		~${className}(void);
		std::map<std::string, ${className}_table> m_data;
		static const char* fileName();
		std::string Error;
		
		${className}_table* get${className}Vo(${parameter});
		std::string int2String(int num);
	};
}

#endif  // __TABLES_${className}_H__

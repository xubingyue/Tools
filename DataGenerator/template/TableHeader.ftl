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
			<#list messages as message>
			memset(&${message.name}, 0, sizeof(${message.name}));
			</#list>
		}
	};

	class ${className}
	{
	public:
		${className}(unsigned const char* data, size_t size);
		~${className}(void);
		std::map<const char*, std::unique_ptr<${className}_table>> m_data;
		static const char* fileName();
		std::string Error;
		
		${className}_table* get${className}Vo(${parameter});
		const char* int2String(int num);
	};
}

#endif  // __TABLES_${className}_H__

#ifndef _ENCO3D_CONFIG_H_
#define _ENCO3D_CONFIG_H_

#include <string>
#include <fstream>
#include <streambuf>
#include <json\json.h>

namespace Enco3D
{
	namespace IO
	{
		namespace ConfigType
		{
			enum ConfigTypes
			{
				JSON
			};
		}

		class Config
		{
		public:
			Config(const std::string& content, ConfigType::ConfigTypes type);
			~Config();

			static Config FromFile(const std::string& file, ConfigType::ConfigTypes type);

			Json::Value JSONDocument;
			Json::Reader JSONReader;

		protected:
			ConfigType::ConfigTypes configType;
		};
	}
}
#endif
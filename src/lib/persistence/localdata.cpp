#include "localdata.h"

//Same relative naming on any OS

//static 
const std::filesystem::path LocalData::RELATIVE_APP_DIR_SUBTREE = std::filesystem::path("AvalonianGps");

//static 
const std::filesystem::path LocalData::RELATIVE_CONFIG_FILE_SUBTREE = LocalData::RELATIVE_APP_DIR_SUBTREE / "settings.conf";

//static
bool LocalData::openStreamOnConfig_(std::ifstream& stream_, std::filesystem::path absolutePath_)
{
	const std::filesystem::path configFilePath = absolutePath_ / RELATIVE_CONFIG_FILE_SUBTREE;
	stream_.open(configFilePath);

	if (!stream_.is_open())
		return false;

	if (!stream_.good())
		return false;

	return true;
}

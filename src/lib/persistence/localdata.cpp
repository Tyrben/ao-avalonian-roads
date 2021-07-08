#include "localdata.h"

//Same relative naming on any OS

//static 
const std::filesystem::path LocalData::RELATIVE_APP_DIR_SUBTREE = std::filesystem::path("AvalonianGps");

//static 
const std::filesystem::path LocalData::RELATIVE_CONFIG_FILE_SUBTREE = LocalData::RELATIVE_APP_DIR_SUBTREE / "settings.conf";

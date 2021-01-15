#include "localdata.h"

#include <cstdlib> //getenv

//SEE https://stackoverflow.com/questions/1024114/location-of-ini-config-files-in-linux-unix
//and https://ploum.net/207-modify-your-application-to-use-xdg-folders/

std::filesystem::path getPathToXDGData()
{
	char* out = std::getenv("XDG_DATA_HOME"); //DO NOT free the returned string
	if (out)
	{
		// XDG_DATA_HOME is set
	}
	else
	{
		// XDG_DATA_HOME is not set
	}
}

//static
bool LocalData::openStreamOnConfig(std::ifstream& stream_)
{
	stream_.open("$XDG_DATA_HOME/" + RELATIVE_CONFIG_FILE_SUBTREE.string());

	if (!stream_.is_open())
		return false;

	if (!stream_.good())
		return false;

	return true;
}



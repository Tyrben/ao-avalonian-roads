#include "localdata.h"

#include <cstdlib> //getenv

//SEE https://stackoverflow.com/questions/1024114/location-of-ini-config-files-in-linux-unix
//and https://ploum.net/207-modify-your-application-to-use-xdg-folders/

std::filesystem::path getPathToXDGData()
{
	const char* out = std::getenv("XDG_DATA_HOME"); //DO NOT free the returned string
	if (out)
	{
		// XDG_DATA_HOME is set
		return std::filesystem::path(out);
	}
	else
	{
		// XDG_DATA_HOME is not set
		return std::filesystem::path();
	}
}

//static
bool LocalData::openStreamOnConfig(std::ifstream& stream_)
{
	const std::filesystem::path configFilePath = getPathToXDGData() /
RELATIVE_CONFIG_FILE_SUBTREE;
	stream_.open(configFilePath);

	if (!stream_.is_open())
		return false;

	if (!stream_.good())
		return false;

	return true;
}

std::string LocalData::getUserDataDirectory()
{
	#if defined (_WIN32)
	const char *environment = std::getenv("APPDATA");
	std::string homeDirectory = (environment ? environment : ".");

	#elif defined (GB_ANDROID_BUILD)

	std::string homeDirectory = RealInstanceDelegator().SDL_AndroidGetInternalStoragePath();

	#else
	// IF ON LINUX

	std::string homeDirectory(".");
	// See https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html
	const char *environment = std::getenv("XDG_DATA_HOME");
	if (NULL == environment || std::strcmp(environment, ""))
	{
		const char *home = std::getenv("HOME");
		homeDirectory = (home ? home + std::string("/.local/share") : ".");
	}
	else
	{
		homeDirectory = environment;
	}
	#endif

	return homeDirectory + "/" + Version::PROJECT_NAME + Version::DEMO_STATUS;
}



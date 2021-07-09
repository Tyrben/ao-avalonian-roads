#include "localdata.h"

#include <cstdlib> //getenv
#include <cstring> //strcmp

#include <iostream> //debug

/*
Linux best practices

Read https://stackoverflow.com/questions/1024114/location-of-ini-config-files-in-linux-unix
and https://ploum.net/207-modify-your-application-to-use-xdg-folders/
and https://specifications.freedesktop.org/basedir-spec/basedir-spec-latest.html

User preferences != User data

XDG_DATA_HOME personnal files

XDG_CONFIG_HOME software configurations

HOME/.mysoftware historical practice, deprecated

There is a xdg lib

*/


//Si XDG_CONFIG_HOME pas définie alors "$HOME/.config"

std::filesystem::path getPathToUserConfigDirectory()
{
	std::filesystem::path dirPath(".");

	const char* configHome = std::getenv("XDG_CONFIG_HOME");
	if (!configHome || std::strcmp(configHome, ""))
	{
		const char* home = std::getenv("HOME");
		dirPath = home ? home + std::string("/.config") : ".";
	}
	else
	{
		dirPath = configHome;
	}

	return dirPath;
}

std::filesystem::path getPathToUserDataDirectory()
{
	std::filesystem::path dirPath(".");

	const char *dataHome = std::getenv("XDG_DATA_HOME");
	if (!dataHome || std::strcmp(dataHome, ""))
	{
		const char *home = std::getenv("HOME");
		dirPath = home ? home + std::string("/.local/share") : ".";
	}
	else
	{
		dirPath = dataHome;
	}

	return dirPath;

	//The project version number could interest this part Version::PROJECT_NAME + Version::DEMO_STATUS;
}

/*
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
		return std::filesystem::path(); // $HOME/.something   ??
	}
}*/

//static
bool LocalData::openStreamOnConfig(std::ifstream& stream_)
{
	return openStreamOnConfig_(stream_, getPathToUserDataDirectory());
}


/*
For a later version

#ifdef GB_ANDROID_BUILD
	std::string homeDirectory = RealInstanceDelegator().SDL_AndroidGetInternalStoragePath();
#endif
*/

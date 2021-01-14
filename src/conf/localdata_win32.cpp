#include "localdata.h"

#include <windows.h> //Mandatory, and always first
#include <shlobj.h> //SHGetKnownFolderPath
#include <combaseapi.h> //CoTaskMemFree

std::filesystem::path getPathToRoamingAppData()
{
	PWSTR pathPWSTR = NULL;

	HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &pathPWSTR);
	//FOLDERID_ProgramFiles

	if (SUCCEEDED(hr))
	{
		wprintf(L"%ls\n", pathPWSTR);
	}

	std::filesystem::path pathResult = pathPWSTR;
	CoTaskMemFree((LPVOID)pathPWSTR);

	return pathResult;
}

//static
bool LocalData::openStreamOnConfig(std::ifstream& stream_)
{
	const std::filesystem::path configFilePath = getPathToRoamingAppData() / RELATIVE_CONFIG_FILE_SUBTREE;
	stream_.open(configFilePath);

	if (!stream_.is_open())
		return false;

	if (!stream_.good())
		return false;

	return true;
}

//static
bool LocalData::openStreamOnConfig(std::ofstream& stream_)
{
	return true;
}

//static
bool LocalData::openStreamOnStaticMaps(std::ifstream& stream_)
{
	return true;
}

//static
bool LocalData::openStreamOnStaticPortals(std::ifstream& stream_)
{
	return true;
}

//static
bool LocalData::openStreamOnDynamicMaps(std::ifstream& stream_)
{
	return true;
}

//static
bool LocalData::openStreamOnDynamicPortals(std::ifstream& stream_)
{
	return true;
}

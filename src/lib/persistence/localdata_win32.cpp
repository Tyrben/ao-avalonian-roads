#include "localdata.h"

#include <windows.h> //Mandatory, and always first
#include <shlobj.h> //SHGetKnownFolderPath
#include <combaseapi.h> //CoTaskMemFree


/*
Windows best practices

Roaming = %appdata% 
is for this user on all the machines of the domain

Local = %localappdata% 
is for this user on this computer (specific or too large)

LocalLow = %appdata%/../LocalLow
is a write protected mode of local

Roaming is under C:\Users\myUser\AppData\Roaming\MyApp
Local is under C:\Users\myUser\AppData\Local\MyApp
LocalLow is under C:\Users\myUser\AppData\Local\MyApp
*/

//local
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
	return openStreamOnConfig_(stream_, getPathToRoamingAppData());
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

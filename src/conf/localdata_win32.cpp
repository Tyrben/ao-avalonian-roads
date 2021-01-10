#include "localdata.h"

#include <windows.h> //Mandatory, and always first
#include <shlobj.h> //SHGetKnownFolderPath
#include <combaseapi.h> //CoTaskMemFree

PWSTR path = NULL;

HRESULT hr = SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, NULL, &path);
//FOLDERID_ProgramFiles

if (SUCCEEDED(hr))
{
	wprintf(L"%ls\n", path);
}

std::filesystem::path path = path;
CoTaskMemFree((LPVOID)path);

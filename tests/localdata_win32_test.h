#pragma once

TEST_CASE("LocalData can open a stream to the config file (windows)", "[LocalData]") {
	LPWSTR tempPath = new WCHAR[256];
	::GetTempPath(256, tempPath);

	std::ofstream tempFile;
	tempFile.open(std::filesystem::path(tempPath) / "settings.conf");
	tempFile << "something";

	delete tempPath;
	tempFile.close();
	//DWORD tempPath[256];
	//::GetTempPath((sizeof tempPath) / (sizeof *tempPath), tempPath);


	//const DWORD bufferSize = ::GetTempPath(0u, nullptr) + 1u;



	std::ifstream inputConfig;
	LocalData::openStreamOnConfig_(inputConfig, std::filesystem::path(tempPath));
	REQUIRE(inputConfig.is_open());
	REQUIRE(inputConfig.good());
}
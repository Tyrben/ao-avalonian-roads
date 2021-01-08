#pragma once
#include <ini/iniformat.h>

#include <filesystem>
#include <fstream>

std::string prepareIniTestFile()
{
	std::filesystem::path ph = std::filesystem::temp_directory_path();
	std::filesystem::create_directories(ph);
	ph /= "test.ini";

	std::ofstream outputFile(ph.string());

	if (!outputFile.is_open()) throw std::runtime_error("Could not open file");

	outputFile << "toto=tata";

	return ph.string();
}

TEST_CASE( "Ini can load a stream", "[Ini]" ) {
	std::string filename = prepareIniTestFile();

	IniFormat ini;
	ini.loadFromFile(filename);
	REQUIRE(true);
}

#pragma once

//WIP #include "../tools/stringtools.h"

#include <map>
#include <string>

class IniFormat
{
public:
	IniFormat() = default;
	IniFormat(std::string filename_); // TODO only accept std::filesystem::file

	void loadFromFile(const std::string& filename_);
	void loadFromFile(std::string&& filename_);

private:
	std::map<std::string, std::string> m_parameters;
};

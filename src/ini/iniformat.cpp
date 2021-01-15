#include "iniformat.h"

#include <algorithm>
#include <cctype> //isspace
#include <fstream>
#include <iostream>
#include <locale> //isspace

void IniFormat::loadFromFile(const std::string& filename_)
{
	std::ifstream cFile(filename_);
	if (!cFile.is_open())
	{
		std::cerr << "Couldn't open config file for reading: " << filename_ << '\n';
		return;
	}

	std::string line;
	while (std::getline(cFile, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), ::isspace),
			line.end());
		if (line[0] == '#' || line[0] == ';' || line[0] == '[' || line.empty())
			continue;
		auto delimiterPos = line.find("=");
		auto name = line.substr(0, delimiterPos);
		auto value = line.substr(delimiterPos + 1);
		m_parameters[name] = value;
		std::cout << name << "= " << value << '\n';
	}
}

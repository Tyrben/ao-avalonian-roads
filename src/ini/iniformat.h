
std::ifstream cFile("config2.txt");
if (!cFile.is_open())
{
	std::cerr << "Couldn't open config file for reading.\n";
	return;
}

std::string line;
while (std::getline(cFile, line))
{
	line.erase(std::remove_if(line.begin(), line.end(), isspace),
		line.end());
	if (line[0] == '#' || line.empty())
		continue;
	auto delimiterPos = line.find("=");
	auto name = line.substr(0, delimiterPos);
	auto value = line.substr(delimiterPos + 1);
	std::cout << name << " " << value << '\n';
}


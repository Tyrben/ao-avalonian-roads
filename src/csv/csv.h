#pragma once
//Inspired from https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp

#include <string>
#include <variant>
#include <vector>

using Cell = std::variant<int, double, std::string>;
using Record = std::vector<Cell>;
//using Column = std::pair<std::string, std::vector<int>>;
using DataSet = std::vector<Record>;

class CsvFormat
{
public:
	void setSeparator(char separator_);
	void loadFromFile(std::string filename_);
	void writeToFile(std::string filename_) const;

	void fromString(std::string filename_);
	std::string toString() const;

private:
	bool m_hasHeaders:
	std::vector<std::string> m_headers;
	DataSet m_dataset;
	char m_separator = ',';
};

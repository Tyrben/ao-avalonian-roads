#pragma once
//Inspired from https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp

#include <string>
#include <variant>
#include <vector>

using Cell = std::variant<int, double, std::string>;
using Line = std::vector<Cell>;
//using Column = std::pair<std::string, std::vector<int>>;
using DataSet = std::vector<Line>;

class CsvFormat
{
public:
	void setSeparator(char separator_);
	void loadFrom(std::string filename_);
	void writeTo(std::string filename_) const;

private:
	DataSet m_dataset;
	char m_separator = ',';
};

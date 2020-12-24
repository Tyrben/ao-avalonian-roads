#pragma once
//First inspired from https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp

#include <string>
#include <variant>
#include <vector>

/**
 * Simple accessor to csv format, read and write
 **/
class CsvFormat
{
public:
	using Cell = std::variant<int, double, std::string>; //TODO dates?
	using Record = std::vector<Cell>;
	using DataSet = std::vector<Record>;

	CsvFormat(std::string filename_ = "");

	void setDelimiter(char);
	void loadFromFile(std::string filename_, bool firstLineIsHeader_ = false);
	void writeToFile(std::string filename_) const;

	Record splitLine(std::string line_) const;
	std::string joinLine(const Record& record_) const;

	//void fromString(std::string filename_);
	//std::string toString() const;

private:
	bool m_hasHeaders;
	Record m_headers;
	DataSet m_dataset;
	char m_delimiter = ',';
};

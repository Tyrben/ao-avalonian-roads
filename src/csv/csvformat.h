#pragma once
//First inspired from https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp

#include <iostream>
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

	static Record splitLine(std::string line_, char delimiter_ = DEFAULT_DELIMITER);
	static std::string joinLine(const Record& record_, char delimiter_ = DEFAULT_DELIMITER);

	//void fromString(std::string filename_);
	//std::string toString() const;

	const Record& getHeader() const;
	const DataSet& getData() const;

private:
	/**
	 * Serialize
	 */
	friend std::ostream& operator<< (std::ostream&, const CsvFormat&);

	/**
	 * Deserialize = loading from file
	 */
	friend std::istream& operator>> (std::istream&, CsvFormat&);

	static char DEFAULT_DELIMITER;
	bool m_hasHeaders;
	Record m_headers;
	DataSet m_dataset;
	char m_delimiter = DEFAULT_DELIMITER;
};

//TODO implement a manipulator to manage the header in and out
std::ostream& operator<< (std::ostream&, const CsvFormat&);
std::istream& operator>> (std::istream&, CsvFormat&);

#include "csvformat.h"

#include <iterator>
#include <sstream>
#include <string>

// Inspired from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
// Took in consideration https://codereview.stackexchange.com/questions/211826/code-to-read-and-write-csv-files
#include <fstream>

//static
char CsvFormat::DEFAULT_DELIMITER = ',';

//static
CsvFormat::Record CsvFormat::splitLine(std::string line_, char delimiter_)
{
	std::vector<Cell> tokens;
	std::string token;
	std::istringstream tokenStream(line_);
	while (std::getline(tokenStream, token, delimiter_))
	{
		tokens.push_back(token);
	}
	return tokens;
}

//static
std::string CsvFormat::joinLine(const CsvFormat::Record& record_, char delimiter_)
{
	std::stringstream result;
	for (CsvFormat::Record::const_iterator cell = record_.begin(); cell != record_.end(); ++cell)
	{
		if (cell != record_.begin())
		result << delimiter_;

		result << std::get<std::string>(*cell);
	}

	return result.str();
}

CsvFormat::CsvFormat(std::string filename_)
{
	loadFromFile(filename_);
}

void CsvFormat::setDelimiter(char delimiter_)
{
	m_delimiter = delimiter_;
}

void CsvFormat::loadFromFile(std::string filename_, bool firstLineIsHeader_)
{
	std::ifstream inputFile(filename_);

	if (!inputFile.is_open()) throw std::runtime_error("Could not open file");
	if (!inputFile.good())
		return;

	m_hasHeaders = firstLineIsHeader_;
	inputFile >> *this;
}

void CsvFormat::writeToFile(std::string filename_) const
{
	std::ofstream outputFile(filename_);

	if (!outputFile.is_open()) throw std::runtime_error("Could not open file");

	if (m_hasHeaders)
		joinLine(m_headers);
}

const CsvFormat::Record& CsvFormat::getHeader() const
{
	return m_headers;
}

const CsvFormat::DataSet& CsvFormat::getData() const
{
	return m_dataset;
}

std::ostream& operator<< (std::ostream& os_, const CsvFormat& csv_)
{
	for (const CsvFormat::Record& line: csv_.m_dataset)
		os_ << CsvFormat::joinLine(line);

	return os_;
}

std::istream& operator>> (std::istream& is_, CsvFormat& csv_)
{
	std::string line;
	if (csv_.m_hasHeaders)
	{
		if (std::getline(is_, line))
			csv_.m_headers = CsvFormat::splitLine(line);
	}

	while (std::getline(is_, line))
		csv_.m_dataset.emplace_back(CsvFormat::splitLine(line));

	return is_;
}

#include "csvformat.h"

#include <iterator>
#include <sstream>
#include <string>

// Inspired from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
// Took in consideration https://codereview.stackexchange.com/questions/211826/code-to-read-and-write-csv-files
#include <fstream>

CsvFormat::CsvFormat(std::string filename_)
{

}

void CsvFormat::setDelimiter(char delimiter_)
{
	m_delimiter = delimiter_;
}

CsvFormat::Record CsvFormat::splitLine(std::string line_) const //split
{
	std::vector<Cell> tokens;
	std::string token;
	std::istringstream tokenStream(line_);
	while (std::getline(tokenStream, token, m_delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::string CsvFormat::joinLine(const CsvFormat::Record& record_) const
{
	std::stringstream result;
	for (CsvFormat::Record::const_iterator cell = record_.begin(); cell != record_.end(); ++cell)
	{
		if (cell != record_.begin())
			result << m_delimiter;

		result << std::get<std::string>(*cell);
	}

	return result.str();
}

void CsvFormat::loadFromFile(std::string filename_, bool firstLineIsHeader_)
{
	std::ifstream inputFile(filename_);

	if (!inputFile.is_open()) throw std::runtime_error("Could not open file");
	if (!inputFile.good())
		return;

	std::string line;
	if (firstLineIsHeader_)
	{
		if (std::getline(inputFile, line))
		{
			m_hasHeaders = true;
			m_headers = splitLine(line);
		}
	}

	while (std::getline(inputFile, line))
	{
		m_dataset.emplace_back(splitLine(line));
	}
}

void CsvFormat::writeToFile(std::string filename_) const
{
	std::ofstream outputFile(filename_);

	// Make sure the file is open
	if (!outputFile.is_open()) throw std::runtime_error("Could not open file");

	if (m_hasHeaders)
		joinLine(m_headers);

	for (const Record& line: m_dataset)
		joinLine(line);
}

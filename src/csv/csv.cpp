#include "csv.h"

//TODO https://codereview.stackexchange.com/questions/211826/code-to-read-and-write-csv-files
#include <fstream>

void CsvFormat::setSeparator(char separator_)
{
	m_separator = separator_;
}

void CsvFormat::loadFrom(std::string filename_)
{
	// Reads a CSV file into a vector of <string, vector<int>> pairs where
	// each pair represents <column name, column values>

	// Create an input filestream
	std::ifstream myFile(filename_);

	// Make sure the file is open
	if (!myFile.is_open()) throw std::runtime_error("Could not open file");

	// Helper vars
	std::string line, colname;
	int val;

	// Read the column names
	if (myFile.good())
	{
		// Extract the first line in the file
		std::getline(myFile, line);

		// Create a stringstream from line
		std::stringstream ss(line);

		// Extract each column name
		while (std::getline(ss, colname, m_separator))
		{

			// Initialize and add <colname, int vector> pairs to result
			m_dataset.push_back({ colname, std::vector<int> {} });
		}
	}

	// Read data, line by line
	while (std::getline(myFile, line))
	{
		// Create a stringstream of the current line
		std::stringstream ss(line);

		// Keep track of the current column index
		int colIdx = 0;

		// Extract each integer
		while (ss >> val)
		{
			// Add the current integer to the 'colIdx' column's values vector
			m_dataset.at(colIdx).second.push_back(val);

			// If the next token is a comma, ignore it and move on
			if (ss.peek() == m_separator) ss.ignore();

			// Increment the column index
			colIdx++;
		}
	}

	// Close file
	myFile.close();
}

void CsvFormat::writeTo(std::string filename_) const
{
	// Make a CSV file with one or more columns of integer values
	// Each column of data is represented by the pair <column name, column data>
	//   as std::pair<std::string, std::vector<int>>
	// The dataset is represented as a vector of these columns
	// Note that all columns should be the same size

	// Create an output filestream object
	std::ofstream myFile(filename_);

	// Send column names to the stream
	for (int j = 0; j < m_dataset.size(); ++j)
	{
		myFile << m_dataset.at(j).first;
		if (j != m_dataset.size() - 1) myFile << m_separator; // No comma at end of line
	}
	myFile << '\n';

	// Send data to the stream
	for (int i = 0; i < m_dataset.at(0).second.size(); ++i)
	{
		for (int j = 0; j < m_dataset.size(); ++j)
		{
			myFile << m_dataset.at(j).second.at(i);
			if (j != m_dataset.size() - 1) myFile << m_separator; // No comma at end of line
		}
		myFile << '\n';
	}

	// Close the file
	myFile.close();
}

#pragma once

#include <csv/csvformat.h>

#include <filesystem>
#include <fstream>
#include <string>

std::string prepareTestFile()
{
	std::filesystem::path ph("/tmp/test.csv"); //= std::filesystem::temp_directory_path() / std::filesystem::path("test.csv");
	//std::filesystem::create_directories(ph);

	std::ofstream outputFile(ph.string());

	if (!outputFile.is_open()) throw std::runtime_error("Could not open file");

	outputFile << "test;is;valid";

	return ph.string();
}

TEST_CASE("CsvFormat can parse a simple line", "[Csv]") {
	std::string simpleLine("aaa,bbb");
	CsvFormat csv;
	CsvFormat::Record rec = csv.splitLine(simpleLine);

	REQUIRE(std::get<std::string>(rec.at(0)) == "aaa");
	REQUIRE(std::get<std::string>(rec.at(1)) == "bbb");
}

TEST_CASE("CsvFormat can parse a complex line", "[Csv]") {
	std::string complexLine("aaa,bbb,3,ddd");
	CsvFormat csv;
	CsvFormat::Record rec = csv.splitLine(complexLine);

	REQUIRE(std::get<std::string>(rec.at(0)) == "aaa");
	REQUIRE(std::get<std::string>(rec.at(1)) == "bbb");
	REQUIRE(std::get<std::string>(rec.at(2)) == "3");
	REQUIRE(std::get<std::string>(rec.at(3)) == "ddd");
}

TEST_CASE("CsvFormat can deserialize a stream", "[Csv]") {
	std::stringstream stream;
	std::string complexLine("aaa,bbb,3,ddd");
	stream << complexLine;

	CsvFormat csv;
	stream >> csv;

	CsvFormat::Record rec = csv.getHeader();

	REQUIRE(std::get<std::string>(rec.at(0)) == "aaa");
	REQUIRE(std::get<std::string>(rec.at(1)) == "bbb");
	REQUIRE(std::get<std::string>(rec.at(2)) == "3");
	REQUIRE(std::get<std::string>(rec.at(3)) == "ddd");
}

TEST_CASE("CsvFormat can load a file", "[Csv]") {
	std::string filename = prepareTestFile();

	CsvFormat csv;
	csv.loadFromFile(filename, true);

	CsvFormat::Record rec = csv.getHeader();

	REQUIRE(std::get<std::string>(rec.at(0)) == "aaa");
	REQUIRE(std::get<std::string>(rec.at(1)) == "bbb");
	REQUIRE(std::get<std::string>(rec.at(2)) == "3");
	REQUIRE(std::get<std::string>(rec.at(3)) == "ddd");
}

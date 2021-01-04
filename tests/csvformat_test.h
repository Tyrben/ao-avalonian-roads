#pragma once

#include <csv/csvformat.h>

#include <string>

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

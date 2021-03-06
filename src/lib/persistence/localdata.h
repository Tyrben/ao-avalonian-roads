#pragma once

#include <filesystem>
#include <fstream>

struct LocalData
{
	static const std::filesystem::path RELATIVE_APP_DIR_SUBTREE;
	static const std::filesystem::path RELATIVE_CONFIG_FILE_SUBTREE;

	static bool openStreamOnConfig(std::ifstream& stream_);
	static bool openStreamOnConfig(std::ofstream& stream_);
	static bool openStreamOnStaticMaps(std::ifstream& stream_);
	static bool openStreamOnStaticPortals(std::ifstream& stream_);
	static bool openStreamOnDynamicMaps(std::ifstream& stream_);
	static bool openStreamOnDynamicPortals(std::ifstream& stream_);

//testable
	static bool openStreamOnConfig_(std::ifstream& stream_, std::filesystem::path absolutePath_);
};

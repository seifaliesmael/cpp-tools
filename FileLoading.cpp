#include "FileLoading.h"

#include <string>
#include <fstream>
#include <vector>
#include <optional>

// Reads a file at {filePath} and returns an optional vector of lines (or std::nullopt if failed to open file)
std::optional<Lines> getLinesFromFile(const std::string& filePath)
{
	// Open stream with file
	std::ifstream file(filePath);

	if (!file.is_open())
		return std::nullopt;

	// Result vector
	Lines res;

	// Iterate through lines (consume from buffer) and add to vector
	std::string curr;
	while (std::getline(file, curr))
	{
		res.push_back(curr);
	}

	// Close file stream
	file.close();

	return res;
}
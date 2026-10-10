#include <iostream>
#include <vector>
#include "FileLoading.h"
#include <optional>

int main()
{
	const std::string filePath = "myTextFile.txt";
	std::optional<std::vector<std::string>> fileLines = getLinesFromFile(filePath);

	if (!fileLines)
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::cout << "Lines: " << std::endl;
	for (const std::string& line : *fileLines)
	{
		std::cout << line << std::endl;
	}

	return 0;
}
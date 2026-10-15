#include <iostream>
#include <vector>
#include "FileLoading.h"
#include <optional>
#include <utility>
#include "DiffEngine.h"

int main()
{
	const std::string filePath1 = "myTextFile1.txt";
	std::optional<std::vector<std::string>> fileLines1 = getLinesFromFile(filePath1);

	if (!fileLines1)
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}


	const std::string filePath2 = "myTextFile2.txt";
	std::optional<std::vector<std::string>> fileLines2 = getLinesFromFile(filePath2);

	if (!fileLines2)
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::vector<std::string> diff = getDiff(*fileLines1, *fileLines2);
	std::cout << "File (" << filePath1 << ") to File (" << filePath2 << ")" << ", Diff:" << std::endl;
	for (const std::string& line : diff)
	{
		std::cout << line << std::endl;
	}


	return 0;
}
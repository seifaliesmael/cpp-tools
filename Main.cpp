#include <iostream>
#include <vector>
#include "FileLoading.h"
#include <optional>
#include <utility>
#include "DiffEngine.h"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "Please enter in two valid file paths as arguments. For example: cpptools.exe myFile1.txt myFile2.txt" << std::endl;
		return 1;
	}

	const std::string filePath1 = argv[1];
	std::optional<std::vector<std::string>> fileLines1 = getLinesFromFile(filePath1);

	if (!fileLines1)
	{
		std::cout << "Failed to open file. Please verify the file path is correct." << std::endl;
		return 1;
	}


	const std::string filePath2 = argv[2];
	std::optional<std::vector<std::string>> fileLines2 = getLinesFromFile(filePath2);

	if (!fileLines2)
	{
		std::cout << "Failed to open file 2. Please verify the file path is correct." << std::endl;
		return 1;
	}

	std::cout << "Analysing diff from " << filePath1 << " to " << filePath2 << "." << std::endl;

	std::vector<std::string> diff = getDiff(*fileLines1, *fileLines2);
	for (const std::string& line : diff)
	{
		std::cout << line << std::endl;
	}


	return 0;
}
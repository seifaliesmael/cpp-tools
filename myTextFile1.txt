#include <iostream>
#include <vector>
#include "FileLoading.h"
#include <optional>
#include "Algorithms.h"

int main()
{
	const std::string filePath1 = "myTextFile1.txt";
	std::optional<std::vector<std::string>> fileLines1 = getLinesFromFile(filePath1);

	if (!fileLines1)
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::cout << "Lines1: " << std::endl;
	for (const std::string& line : *fileLines1)
	{
		std::cout << line << std::endl;
	}

	const std::string filePath2 = "myTextFile2.txt";
	std::optional<std::vector<std::string>> fileLines2 = getLinesFromFile(filePath2);

	if (!fileLines2)
	{
		std::cout << "Failed to open file" << std::endl;
		return 1;
	}

	std::cout << "Lines2: " << std::endl;
	for (const std::string& line : *fileLines2)
	{
		std::cout << line << std::endl;
	}

	int lengthOfLCS = longestCommonSubsequence(*fileLines1, *fileLines2);
	std::cout << "Length of LCS: " << lengthOfLCS << std::endl;

	return 0;
}
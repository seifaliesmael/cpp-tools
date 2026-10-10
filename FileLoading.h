#pragma once
#include <string>
#include <vector>
#include <optional>

std::optional<std::vector<std::string>> getLinesFromFile(const std::string& filePath);

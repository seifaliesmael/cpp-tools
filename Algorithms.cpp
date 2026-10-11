#include "Algorithms.h"
#include <vector>
#include <string>
#include <algorithm>

// Get length of longest common subsequence
int longestCommonSubsequence(const std::vector<std::string>& lines1, const std::vector<std::string>& lines2)
{
	// Initialise 2D DP Array
	std::vector<std::vector<int>> dp(lines1.size() + 1, std::vector<int>(lines2.size() + 1, 0));

	// Iterate backwards from the bottom right corner
	for (int i = lines1.size() - 1; i >= 0; i--)
	{
		for (int j = lines2.size() - 1; j >= 0; j--)
		{
			if (lines1[i] == lines2[j])
			{
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else
			{
				dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	return dp[0][0];

}
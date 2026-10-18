#include "DiffEngine.h"
#include <vector>
#include <string>
#include <algorithm>

// Get diff from one file's lines to another
Lines getDiff(const Lines& lines1, const Lines& lines2)
{
	// Initialise 2D DP Array
	// Rows, Cols
	// Each cell dp[i][j] is the length of the LCS between lines1[i:], lines2[j:]
	std::vector<std::vector<int>> dp(lines1.size() + 1, std::vector<int> (lines2.size() + 1, 0));

	// TODO: Optimise this vector by using one big vector instead of sub-vectors.

	// Iterate backwards from the bottom right corner and calculate length of LCS at each step.
	for (int i = lines1.size() - 1; i >= 0; i--)
	{
		for (int j = lines2.size() - 1; j >= 0; j--)
		{
			if (lines1[i] == lines2[j])
			{
				// Same, take and check lines[i+1:] and lines[j+1:]
				// Take LCS of i+1 onwards and j+1 onwards, increment length by 1.
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else
			{
				// Not the same.
				// Check cell to the right (lines1[i:], lines2[j+1:]
				// and cell below (lines1[i+1:], lines2[j:])
				dp[i][j] = std::max(dp[i][j + 1], dp[i + 1][j]);
			}
		}
	}

	// Build the diff itself
	int i = 0;
	int j = 0;
	Lines diff;

	while (i < lines1.size() && j < lines2.size())
	{
		if (lines1[i] == lines2[j])
		{
			// This line is part of the LCS and line was kept
			diff.push_back("  " + lines1[i]);
			i += 1;
			j += 1;
		}
		else
		{
			// Check bottom cell and right cell
			if (dp[i][j + 1] > dp[i + 1][j])
			{
				// Right cell has a longer LCS, go to it
				// This means we are adding a new line (from lines2)
				diff.push_back("+ " + lines2[j]);
				j += 1;
			}
			else
			{
				// Bottom cell is longer or equal, go to it
				// This means we are removing a line from lines1.
				diff.push_back("- " + lines1[i]);
				i += 1;
			}
		}
	}

	// Leftover removed lines from i
	while (i < lines1.size())
	{
		diff.push_back("- " + lines1[i]);
		i += 1;
	}

	// Fully new lines appended from j
	while (j < lines2.size())
	{
		diff.push_back("+ " + lines2[j]);
		j += 1;
	}

	return diff;

}
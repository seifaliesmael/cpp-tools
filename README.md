# cpp-tools
From-scratch implementations of common utility programs (for now, only diff) implemented by hand in C++.
## Technical Stack
* Pure C++
* CMake for build, dependencies, and running tests.
* GoogleTest for unit testing - automatic verification that the code behaves as expected.
## Overview of Tools
1. **Diff**  
A tool that lets you compare two versions of a file and see what lines were removed or added, as a "line-by-line".  
Usage (example): `cppTools.exe myFile1.txt myFile2.txt` 
The diff algorithm used in the current implementation is LCS (Longest Common Subsequence), a dynamic programming method.  
Time & Space Complexity: O(m * n).  
There are plans to improve this by using Myer's Diff Algorithm which runs in less time.
2. **Fuzzy Search** (PLANNED)  
 Search for a file, allowing for minor spelling mistakes.

## Motivation for Project
This project was started out of curiosity about how common utilities 
work: in particular `git diff`, which we often take for granted as programmers; as well as a way to practice and apply my knowledge of C++.
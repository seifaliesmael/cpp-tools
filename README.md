# cpp-tools
From-scratch implementations of common utility programs (for now, only diff) in C++.
## Technical Stack
* C++17
* CMake for build, dependencies, and running tests.
* GoogleTest for unit testing - automatic verification that the code behaves as expected.
## Overview of Tools
1. **Diff**  
A tool that lets you compare two versions of a file and see what lines were removed or added, as a "line-by-line".  
Usage (example): `CPPTools.exe myFile1.txt myFile2.txt`  
The diff algorithm used in the current implementation is LCS (Longest Common Subsequence), a dynamic programming method.  

	**Time & Space Complexity**: O(m * n).  
There are plans to improve this by using Myers' Diff Algorithm, which runs in O((m + n) * D) time, where D is the number of differences. 
This makes it much faster especially for very similar files (i.e, small changes).
2. **Fuzzy Search** (PLANNED)  
Search for a file, allowing for minor spelling mistakes.

## Motivation for Project
This project was started out of curiosity about how common utilities 
work: in particular `git diff`, which we often take for granted as programmers; as well as a way to practice and apply my knowledge of C++.

## Using the Tool
1. Go to the releases page and download the latest version for your operating system.
2. Open a terminal in the same directory as the downloaded file.
3. Run the application passing in the paths to the two files you want to compare.
```sh
# If on UNIX systems (Linux/MacOS), the file must be made executable first.
chmod +x CPPTools

./CPPTools <filePath1> <filePath2> # UNIX Systems
CPPTools.exe <filePath1> <filePath2> # Windows
```
## Building/Running from Source
### Requirements
1. A C++17 compiler (GCC, Clang, MSVC).
2. CMake 3.23 or newer
3. Ninja (build tool)
4. Internet for the initial configuration, since GoogleTest needs to be fetched.
### Instructions
1. Clone the repository into a local folder.
```sh
git clone https://github.com/seifaliesmael/cpp-tools.git
cd cpp-tools
```
2. Run CMake configuration to detect system and compiler.  
You can select any name for the build directory and the output files will be placed in that folder.  
For example, `.. -B build..` will place files in `cpp-tools/build/`.
```sh
cmake -S . -B <build-directory> -G Ninja
```
This produces a Release build by default. For a Debug build, append `-DCMAKE_BUILD_TYPE=Debug` to the command.

3. Build the application.
```sh
cmake --build <build-directory>
```
4. Run the test suite to ensure the program is well-behaving.
```sh
ctest --test-dir <build-directory>
```
5. Finally, run the application
```sh
# UNIX-based Systems (Linux, MacOS)
./build/CPPTools <filePath1> <filePath2>

# Windows
./build/CPPTools.exe <filePath1> <filePath2>
```

### License
[MIT License](LICENSE)

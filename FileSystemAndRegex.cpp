/*
* Program: This program will search all pdf files which starts with "MyFile_<SomeNumber>" from given directory.
* Compile command: g++ FileSystemAndRegex.cpp -o a.out -std=c++17
* gcc version: 11.2.0 (GCC)
* For more details on file system library: https://en.cppreference.com/w/cpp/filesystem
* For more details on regex library: https://en.cppreference.com/w/cpp/regex
*/

#include <iostream>
#include <string>
#include <filesystem>
#include <regex>

#define PATH "."

int main()
{
    std::string searchPattern = "MyFile_";
    searchPattern += "[0-9]*(\\.zip)$";
    std::cout << "Searching path: " << PATH << std::endl;
    try
    {
        for (const auto& entry : std::filesystem::directory_iterator(PATH))
        {
            if (entry.symlink_status().type() == std::filesystem::file_type::regular)
            {
                if (std::regex_match(entry.path().filename().u8string(), std::regex(searchPattern, std::regex_constants::icase)))
                {
                    std::cout << "\tFound: " << entry.path().filename() << std::endl;
                }
            }
        }
    }
    catch (std::filesystem::filesystem_error const& ex)
    {
        std::cout << "Exception:  " << ex.what() << '\n';
    }

    std::cout << std::endl;

    return 0;
}

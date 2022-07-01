// https://stackoverflow.com/questions/39566662/text-parsing-a-log-file-effectively-in-c

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

const char CDELIMITER = ' ';

int main()
{
    // create a file-reading object
    std::ifstream fin;
    fin.open("templates/strings/stats.txt"); // open a file
    if (!fin.good()) 
        return 1; // exit if file not found

    std::string buf;

    //read the file line by line
    while (std::getline(fin, buf))
    {
        //convert the line in to stream:
        std::istringstream ss(buf);

        //declare vector of string (instead of fixed array)
        std::vector<std::string> vec;

        //read the line, word by word
        while (std::getline(ss, buf, CDELIMITER))
            vec.push_back(buf);

        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "Token[" << i << "] = " << vec[i] << "\n";
        std::cout << "\n";
    }
    return 0;
}

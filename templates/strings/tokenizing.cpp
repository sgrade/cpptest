#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>      // strtok, c_str
#include <iomanip>      // quoted
#include <iterator>     // istream_iterator
#include <regex>

using namespace std;


int main() {

    // C++ strings
    
    string sentence;
    vector<string> words;
    string word;

    /*
    stringstream - works with C++ strings
    clear() — flushes the stream 
    str() —  converts a stream of words into a C++ string object.
    operator << — pushes a string object into the stream.
    operator >> — extracts a word from the stream.
    */

    // Space - delimited
    sentence = "I speak Latin";
    istringstream iss_space_delim(sentence);
    while (iss_space_delim >> word) {
        cout << word.size() << ": " << word << '\n';
        words.emplace_back(word);
    }
    cout << endl;

    // Custom delimitter
    sentence = "C*C++*Java";
    words.clear();
    const char delim = '*';
    istringstream iss_custom_delim(sentence);
    while (getline(iss_custom_delim, word, delim)) {
        words.emplace_back(word);
    }
    for (string &el: words) {
        cout << el << ' ';
    }
    cout << endl << endl;

    // https://stackoverflow.com/questions/60245936/how-do-i-parse-this-file-in-cpp
    string line{ "Token1 Token2 Token3 Token4" };
    
    // Solution 1: Use extractor operator
    string subString1{}, subString2{}, subString3{}, subString4{};
    istringstream iss1(line);
    iss1 >> subString1 >> subString2 >> subString3 >> subString4;
    
    // Solution 2: Use istream_iterator
    // This will call the extractor operator (>>) until all data is consumed. 
    istringstream iss2(line);
    vector istream_token(istream_iterator<string>(iss2), {});

    // Solution 3: Use std::sregex_token_iterator
    const std::regex re(" ");
    vector<string> token2(sregex_token_iterator(line.begin(), line.end(), re, -1), {});
    // 1, if you want to have a positive match for the regex
    // -1, will return everything that not matches the regex

    // Multiple delimiters
    // https://stackoverflow.com/questions/7621727/split-a-string-into-words-by-multiple-delimiters
    // regex: the '-1' is what makes the regex split (-1 := what was not matched)
    string input_delims = "1first,1second: 1third\n2first 2second|2third";
    // Note: the empty substring ("") will be added, when two delims follow each other 
    // (there is no chars in between). E.g. colon and space ": ".
    std::regex re2("[ \\|,:\\n]");
    std::sregex_token_iterator first{input_delims.begin(), input_delims.end(), re2, -1}, last;
    std::vector<std::string> tokens{first, last};
    for (string &t: tokens) {
        cout << "'" << t << "'" << ' ';
    }
    cout << endl << endl;

    // Below only separates using one delim
    // If there are two or more delims in a row, take care of it separately 
    string input_string = "1first,1second: 1third\n2first 2second|2third";
    std::stringstream stringStream(input_string);
    std::string line2;
    vector<string> word_vector;
    while(std::getline(stringStream, line2)) {
        // cout << line2 << endl;
        std::size_t prev = 0, pos;
        while ((pos = line2.find_first_of(" ';:|,", prev)) != std::string::npos)
        {
            if (pos > prev)
                word_vector.push_back(line2.substr(prev, pos-prev));
            prev = pos+1;
        }
        if (prev < line2.length())
            word_vector.push_back(line2.substr(prev, std::string::npos));
    }
    for (string &t: word_vector) {
        cout << "'" << t << "'" << ' ';
    }
    cout << endl << endl;


    // -------------------
    // C strings
    
    // The main disadvantage of strtok() is that it only works for C style strings.
    //  Therefore we need to explicitly convert C++ string into a char array.

    // https://en.cppreference.com/w/cpp/string/byte/strtok
    char input[] = "one + two * (three - four)!";
    const char* delimiters = "! +- (*)";
    char *token = std::strtok(input, delimiters);
    while (token) {
        std::cout << token << ' ';
        token = std::strtok(nullptr, delimiters);
    }
    cout << endl << endl;

    // String to char array
    // https://www.geeksforgeeks.org/convert-string-char-array-cpp/
    string st = "GeeksForGeeks";

    // Method 1:
    char char_array[st.size() + 1];
    strcpy(char_array, st.c_str());
    cout << char_array << endl;

    // Method 4:
    const char *str = st.c_str();
    cout << str << endl;

    return 0;
}

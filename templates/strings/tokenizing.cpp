#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>      // strtok, c_str
#include <iomanip>      // quoted

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
    stringstream iss(sentence);
    while (iss >> word) {
        cout << word.size() << ": " << word << '\n';
        words.emplace_back(word);
    }
    cout << endl;

    // Custom delimitter
    sentence = "C*C++*Java";
    words.clear();
    const char delim = '*';
    stringstream iss2(sentence);
    while (getline(iss2, word, delim)) {
        words.emplace_back(word);
    }
    for (string &el: words) {
        cout << el << ' ';
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

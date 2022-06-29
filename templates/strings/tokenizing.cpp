#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>      // strtok, c_str
#include <iomanip>      // quoted

using namespace std;


int main() {

    string sentence = "I speak Latin";
    
    istringstream iss(sentence);
    string word;
    vector<string> words;
    int i = 1;
    while (iss >> word) {
        cout << word.size() << ": " << word << '\n';
        words.emplace_back(word);
    }
    cout << endl;

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

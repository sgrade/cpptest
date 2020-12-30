// A. Sleuth

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// like Python strip
// https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch) && ch != '?';
    }).base(), s.end());
}


int main(){

    string s;
    getline(cin, s);

    vector<char> vowels = {'A', 'E', 'I', 'O', 'U', 'Y'};
    // vector<char> consonants = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z'};

    rtrim(s);
    char last = toupper(*s.rbegin());

    bool ans = false;
    if(find(vowels.begin(), vowels.end(), last) != vowels.end()) ans = true;

    cout << (ans ? "YES": "NO") << endl;

    return 0;
}

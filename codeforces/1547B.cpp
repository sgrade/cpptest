// B. Alphabetical Strings

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    // 26 letters  
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

    while (t--) {

        string s;
        getline(cin >> ws, s);

        bool ans = true;

        char ch;
        size_t idx_in_alplabet = 0;
        size_t idx = s.find(alphabet[idx_in_alplabet]);

        if (idx != string::npos) {

            int left = idx - 1, right = idx + 1;

            for (int i = 0; i < s.size() - 1; ++i) {
                ++idx_in_alplabet;
                
                if (idx_in_alplabet > 25) {
                    ans = false;
                    break;
                }

                ch = alphabet[idx_in_alplabet];

                if (left >= 0 && s[left] == ch) {
                    --left;
                }

                else if (right < 26 && s[right] == ch) {
                    ++right;
                }

                else {
                    ans = false;
                    break;
                }
            }
            
        }

        else {
            ans = false;
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}

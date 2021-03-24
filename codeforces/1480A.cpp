// A. Yet Another String Game

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    int t;
    cin >> t;

    while (t--) {

        string s;
        getline(cin >> ws, s);
        
        string ans;
        
        char tmp;
        for (int i = 0; i < s.size(); ++i) {
            tmp = s[i];
            
            // Bob's turn
            if (i & 1) {
                ans += *find_if_not(alphabet.rbegin(), alphabet.rend(), [tmp](char ch){
                    return ch == tmp;
                });
            }

            // Alice's turn
            else {
                ans += *find_if_not(alphabet.begin(), alphabet.end(), [tmp](char ch){
                    return ch == tmp;
                });
            }
        }

        cout << ans << endl;
    }

    return 0;
}

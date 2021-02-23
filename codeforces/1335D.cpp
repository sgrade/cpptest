// D. Anti-Sudoku

#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--) {
        vector<string> v(9);
        for (auto &el: v) {
            getline(cin >> ws, el);
        }

        // Key ideas from - https://codeforces.com/contest/1335/submission/95649940
        for (auto s: v) {
            for (auto ch: s) {
                if (ch == '1') putchar('2');
                else putchar(ch);
            }
            cout << endl;
        }

    }
    
    return 0;
}

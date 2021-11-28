// B. William the Vigilant
// Rework required. I wrongly interpreted the task, thus the implementation is also wrong.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;


    int cnt = 0;

    vector<bool> abc(n);

    int p = 0;
    while (true) {
        p = s.find("abc", p);
        if (p != string::npos) {
            ++cnt;
            for (int i = 0; i < 3; ++i) {
                abc[p+i] = true;
            }
            p += 3;
        }
        else {
            break;
        }
    }

    int i;
    char ch;

    vector<int> output(q);
    string pattern = "abc";

    for (int j = 0; j < q; ++j) {
        
        output[j] = cnt;
        
        cin >> i >> ch;
        --i;
        
        if (s[i] != ch) {
            
            if (abc[i] == true) {
                --output[j];
            }

            else {
                int c = pattern.find(ch);
                i -= c;
                int cntr = 0;
                bool found = true;
                for (int k = i; cntr < 3; ++k) {
                    if (k == c) {
                        continue;
                    }
                    if (k == n || abc[k] == true) {
                        found = false;
                    }
                    if (s[i] != pattern[cntr]) {
                        found = false;
                    }
                    ++cntr;
                }
                if (found) {
                    ++output[j];
                }
            }

        }
    }

    for (auto &el: output) {
        cout << el << '\n';
    }

    return 0;
}

// C. Given Length and Sum of Digits...

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int m, s;
    cin >> m >> s;

    string mn = "-1", mx = "-1";

    // Editorial - https://codeforces.com/blog/entry/14741
    if (s > 0 && s <= 9 * m)
    
    {  
        vector<int> digits;
        int tmp = s;
        while (tmp > 0) {
            tmp -= 9;
            digits.push_back(9);
        }
        if (tmp < 0) {
            tmp = 9 + tmp;
            digits.erase(digits.end() - 1);
            digits.push_back(tmp);
        }
        sort(digits.begin(), digits.end());

        // Constructing maximum
        mx = "";
        for (int i = digits.size() - 1; i > -1; --i) {
            mx += to_string(digits[i]);
        }
        int counter = m - digits.size();
        while (counter--) {
            mx += "0";
        }
        
        // Constructing minimum
        mn = "";
        if (digits.size() < m) {
            mn += '1';
            --digits[0];
            counter = m - 1 - digits.size();
            while (counter--) {
                mn += '0';
            }
        }
        for (auto digit: digits) {
            mn += to_string(digit);
        }
    }

    else if (s == 0 && m == 1) {
        mn = "0";
        mx = "0";
    }

    cout << mn << ' ' << mx << endl;

    return 0;
}

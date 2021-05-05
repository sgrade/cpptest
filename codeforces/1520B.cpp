// B. Ordinary Numbers

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;
    
    string s;
    char first_char;
    int first_digit, next_ordinary;
    int ans;
    while (t--) {

        int n;
        cin >> n;

        s = to_string(n);
        int len = s.size();

        first_char = s[0];
        first_digit = first_char - '0';

        ans = (len - 1) * 9;

        s = "";
        for (int i = 0; i < len; ++i) {
            s += first_char;
        }
        next_ordinary = stoi(s);
        if (n >= next_ordinary) {
            ans += first_digit;
        }
        else {
            ans += first_digit - 1;
        }

        cout <<  ans << endl;

    }

    return 0;
}

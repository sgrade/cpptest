// A. Sequence of Comparisons

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        cin >> s;

        char ans;

        auto less = s.find('<');
        auto more = s.find('>');

        bool ls = less != string::npos ? true : false;
        bool mr = more != string::npos ? true : false;

        if (ls && mr) {
            ans = '?';
        }
        else {
            if (ls) {
                ans = '<';
            }
            else if (mr) {
                ans = '>';
            }
            else {
                ans = '=';
            }
        }

        cout << ans << endl;
    }

    return 0;
}

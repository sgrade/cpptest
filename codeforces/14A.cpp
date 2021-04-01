// A. Letter

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<string> v(n);

    size_t left = 51, right = 0, tmp;
    int top = 51, bottom = 0;
    string s;
    for (int i = 0; i < n; ++i) {
        getline(cin >> ws, s);
        v[i] = s;

        tmp = s.find_first_of('*');
        if (tmp != string::npos) {
            left = min(left, tmp);
            right = max(right, s.find_last_of('*'));
            
            top = min(top, i);
            bottom = max(bottom, i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i >= top && i <= bottom) {
            cout << v[i].substr(left, right - left + 1) << endl;
        }
    }


    return 0;
}

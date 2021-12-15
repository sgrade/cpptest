// B. Missing Bigram

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string prev, cur;
        cin >> prev;
        
        vector<char> ans;
        ans.push_back(prev[0]);
        ans.push_back(prev[1]);

        bool filled = false;
        for (int i = 0; i < n-3; ++i) {
            cin >> cur;
            if (cur[0] != *rbegin(ans)) {
                ans.push_back(cur[0]);
                filled = true;
            }
            ans.push_back(cur[1]);
            prev = cur;
        }
        if (!filled) {
            ans.push_back('b');
        }

        for (auto &ch: ans) {
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}

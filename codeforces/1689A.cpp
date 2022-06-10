// A. Lex String
// Wrong answer

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, m, k;
        cin >> n >> m >> k;

        string a, b;
        cin >> a >> b;

        int idx_a = 0, idx_b = 0, k_a = 0, k_b = 0;

        vector<pair<char, char>> x;
        for (char& c: a) {
            x.push_back(pair<char, char>(c, 'a'));
        }
        for (char& c: b) {
            x.push_back(pair<char, char>(c, 'b'));
        }
        sort(x.begin(), x.end());

        vector<char> ans;

        bool flag = false;
        char tmp;
        for (int i = 0; i < x.size(); ++i) {

            if (n == 0 || m == 0) break;

            if (x[i].second == 'a') {
                ++k_a;
            }
            else {
                ++k_b;
            }

            if (k_a > k || k_b > k) {
                for (int j = i + 1; j < x.size(); ++j) {
                    if (x[j].second != x[i].first) {
                        ans.push_back(x[j].first);
                        
                    }
                }
            }
        }

        

        

        for (char &ch: ans) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}

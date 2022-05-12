// G. White-Black Balanced Subtrees

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int ans;

int count_trees (const int x, string &s, vector<vector<int>> &a) {

    int cnt = s[x-1] == 'B' ? -1 : 1;
    
    if (a[x].size() == 0) return cnt;

    for (int &el: a[x]) {
        cnt += count_trees(el, s, a);
    }

    if (cnt == 0) ++ans;

    return cnt; 
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        ans = 0;

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/102710

        vector<vector<int>> a(n + 2);
        int tmp;
        for (int i = 2; i <= n; ++i) {
                cin >> tmp;
                a[tmp].push_back(i);
        }

        string s;
        cin >> s;

        count_trees(1, s, a);
        
        cout << ans << '\n';
    }
}


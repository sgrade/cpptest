// B. Nice Matrix

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

ull equalize(vector<int> &v) {
    ull output = 0ULL;

    sort(v.begin(), v.end());
    int mid = v.size() / 2;
    for (int i = 0; i < v.size(); ++i) {
        output += abs(v[i] - v[mid]);
    }

    return output;
}


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                cin >> a[i][j];
            }
        }

        ull ans = 0ULL;

        // Editorial - https://codeforces.com/blog/entry/83452
        int top = 0, bottom = n-1;
        while (top <= bottom) {
            int left = 0, right = m-1;
            while (left <= right) {
                vector<int> cur = {a[top][left]};
                if (top != bottom) {
                    cur.push_back(a[bottom][left]);
                }
                if (left != right) {
                    cur.push_back(a[top][right]);
                }
                if (top != bottom && left != right) {
                    cur.push_back(a[bottom][right]);
                }

                ans += equalize(cur);

                ++left;
                --right;
            }

            ++top;
            --bottom;
        }
        
        cout << ans << endl;
        
    }

    return 0;
}
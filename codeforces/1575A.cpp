// A. Another Sorting Problem

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Custom sort syntax - https://en.cppreference.com/w/cpp/algorithm/sort
struct {
    bool operator()(pair<string, int> a, pair<string, int> b) const 
    { 
        // Strings are of equal size
        int m = size(a.first);
        for (int i = 0; i < m; ++i) {

            // Same chars
            if (a.first[i] == b.first[i]) {
                continue;
            }

            // Odd-indexed characters are sorted in ascending order
            // Note: 1-based indexes are used in the task, thus checking i+1 instead of i
            if ((i+1) % 2 != 0) {
                return a.first[i] < b.first[i];
            }
            // Even-indexed characters are sorted in descending order
            else {
                return a.first[i] > b.first[i];
            }
        }

        return false;
    }
} compAscDesc;



int main() {

    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    // Idea - https://codeforces.com/contest/1575/submission/130566599
    sort(begin(v), end(v), compAscDesc);

    for (auto &p: v) {
        // Note: 1-based indexes are expeced in the answer, thus adding 1 to the zero-based index
        cout << p.second + 1 << ' ';
    }
    cout << endl;

    return 0;
}

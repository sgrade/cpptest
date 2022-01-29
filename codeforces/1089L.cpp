// L. Lazyland

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(n, vector<int>(2));
    set<int> taken_jobs;
    for (auto &p: a) {
        cin >> p[0];
        taken_jobs.insert(p[0]);
    }
    for (auto &p: a) {
        cin >> p[1];
    }

    sort(begin(a), end(a));

    long long ans = 0;
    multiset<int> duplicates;
    for (int i = n-2; i > -1; --i) {
        if (a[i][0] == a[i+1][0]) {
            duplicates.insert(a[i][1]);
        }
    }

    // not taken jobs
    int ntj = k - size(taken_jobs);
    set<int>::iterator it = begin(duplicates);
    for (int i = 0; i < ntj; ++i) {
        ans += *it;
        ++it;
    }

    cout << ans << '\n';

    return 0;
}

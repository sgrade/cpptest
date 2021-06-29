// C. Little Alawn's Puzzle

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;


int findd (int edge, vector<int> &ids) {
    if (ids[edge] != edge) {
        ids[edge] = findd(ids[edge], ids);
    }
    return ids[edge];
}

void unionn (int edge1, int edge2, vector<int> &ids) {
    int parent1 = findd (edge1, ids);
    int parent2 = findd (edge2, ids);
    ids[parent1] = parent2;
}

int main() {

    int t;
    cin >> t;

    const ll MOD = 1e9 + 7;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> edges(n, vector<int>(2));
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            edges[i][0] = tmp - 1;
        }
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            edges[i][1] = tmp - 1;
        }

        // Editorial - https://codeforces.com/blog/entry/91760
        // Nice explanation - https://www.youtube.com/watch?v=p241TFvSrIg

        // Union find (based on explanation here https://www.youtube.com/watch?v=ymxPZk7TesQ)
        vector<int> ids(n);
        for (int i = 0; i < n; ++i) {
            ids[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            unionn (edges[i][0], edges[i][1], ids);
        }
        
        set<int> st;
        for (int i = 0; i < n; ++i) {
            st.insert(findd(i, ids));
        }

        ll ans = 1;
        int k = st.size();
        for (int i = 0; i < k; ++i) {
            ans = ans * 2LL % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}

// B. Diameter of Graph

#include <iostream>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        --k;
        // Now diameter should be strictly less than k

        // Editorial - https://codeforces.com/blog/entry/95477

        bool ans = false;

        int min_edges = n - 1;
        long long max_edges = n * (n - 1LL) / 2;

        // Not enough edged or too many edges
        if (m >= min_edges && m <= max_edges) {
            
            // Single node graph
            if (n == 1) {
                if (k > 0) {
                    ans = true;
                }
            }

            // not a complete graph, thus d should be >= 2
            if (m < max_edges) {
                if (k > 2) {
                    ans = true;
                }
            }
            else {
                if (k > 1) {
                    ans = true;
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}

// B. Squares and Cubes

#include <iostream>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/98159
        set<int> st;

        for (int i = 1; i * i <= n ; ++i) {
            st.insert(i * i);
        }
        for (int i = 1; i * i * i <= n; ++i) {
            st.insert(i * i * i);
        }

        int ans = size(st);
        cout << ans << endl;
    }

    return 0;
}

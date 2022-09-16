// B. Colourblindness

#include <iostream>
#include <string>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string row1, row2;
        cin >> row1 >> row2;

        bool ans = true;

        for (int i = 0; i < n; ++i) {
            if (row1[i] == 'R' && row2[i] == 'R') {
                continue;
            }
            else if (row1[i] == 'R' || row2[i] == 'R') {
                ans = false;
                break;
            }
        }
        
        cout << (ans ? "YES\n" : "NO\n");
    }

    return 0;
}

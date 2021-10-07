// B. Badge

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 1; i <= n; ++i) {
        vector<bool> visited(n+1);
        visited[i] = true;
        int j = n+1;
        int nxt = p[i];
        while (j--) {
            if (visited[nxt]) {
                cout << nxt << ' ';
                break;
            }
            visited[nxt] = true;
            nxt = p[nxt];
        }
        
    }

    cout << '\n';

    return 0;
}

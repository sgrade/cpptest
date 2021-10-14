    // B. Make it Divisible by 25

    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;


    int main() {

        int n, a, b;
        cin >> n >> a >> b;

        vector<int> h(n);
        for (auto &el: h) {
            cin >> el;
        }
        sort(begin(h), end(h));
        
        // Idea - https://codeforces.com/contest/169/submission/1409337
        int ans = h[b] - h[b-1];

        cout << ans << endl;

        return 0;
    }

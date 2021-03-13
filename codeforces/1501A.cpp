// A. Alexey and Train

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a, b;
        vector<pair<int, int>> v(n);
        for (auto &el: v)
            cin >> el.first >> el.second;

        vector<int> t(n);
        for (auto &el: t) 
            cin >> el;

        unsigned long long ans = 0ULL;

        int delay = 0;
        for (int i = 0; i < n; ++i)
        {
            a = delay + v[i].first + t[i];
            b = (v[i].second - v[i].first + 2 - 1) / 2;
            b = max(a + b, v[i].second);
            delay = b - v[i].second;
        }

        cout << a << endl;
    }

    return 0;
}

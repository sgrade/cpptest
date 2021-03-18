// A. Powered Addition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<long long, long long>> x = {pair(1, 1)};

long long check(long long diff)
{
    auto it = find_if(x.begin(), x.end(), [diff](pair<long long, long long> y){
        return y.second >= diff;
    });
    return distance(x.begin(), it) + 1;
}

int main()
{
    long long tmp = 1;
    for (int i = 1; tmp < 2000000000; ++i)
    {
        tmp *= 2;
        x.emplace_back(pair(tmp, x[i-1].second + tmp));
    }
    
    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &el: a) cin >> el;

        int ans = 0;

        if (n > 1)
        {
            long long max_diff = 0;
            for (int i = 1; i < n; ++i)
            {
                if (a[i] < a[i-1])
                {                   
                    // Idea = https://www.youtube.com/watch?v=CTDM1A1_RKc
                    max_diff = max(max_diff, a[i-1] - a[i]);
                    a[i] = a[i-1];
                }
            }
            if (max_diff > 0)
            {
                ans = check(max_diff);
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}

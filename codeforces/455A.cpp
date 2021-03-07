// A. Boredom

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int tmp;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ++mp[tmp];
        a[i] = tmp;
    }

    vector<unsigned long long> dp;
    // Key ideas - https://www.youtube.com/watch?v=vGTzawku3lM

    dp.push_back(0);
    dp.push_back(mp[1]);
    for (int i = 2; i <= 100000; ++i)
    {
        dp.push_back(max(dp[i-1], 1ULL * i * mp[i] + dp[i-2]));
    }
    
    cout << *dp.rbegin() << endl;

    return 0;
}

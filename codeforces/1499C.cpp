// C. Minimum Grid Path
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;


using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<ull> c(n);
        for (auto &el: c) cin >> el;
        
        vector<ull> v(c.begin(), c.end());
        sort(v.begin(), v.end());

        int nx = n;
        int ny = n;
        map<ull, int> used;
        
        ull cost = 0;      

        cout << cost << endl;
    }

    return 0;
}

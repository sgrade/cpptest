// A. Diverse Team

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    int tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        mp.insert(pair<int, int>(tmp, i+1));
    }

    if (mp.size() < k) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        vector<int> v;
        for (auto it: mp) {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int count = 1;
        for (auto it: v){
            cout << it << ' ';
            ++count;
            if (count > k) break;
        }
        cout << endl;
    }

    return 0;
}
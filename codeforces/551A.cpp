// A. GukiZ and Contest

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;
    
    // Idea - https://codeforces.com/contest/551/submission/12629224
    
    vector<int> v(n);
    for (auto &el: v) cin >> el;

    vector<int> sorted_v(v.begin(), v.end());
    sort(sorted_v.begin(), sorted_v.end(), greater<int>());

    for (auto el: v){
        cout << 1 + distance(sorted_v.begin(), find(sorted_v.begin(), sorted_v.end(), el)) << ' ';
    }
    cout << endl;

    return 0;
}

// A. Paint the Numbers

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &el: v) {
        cin >> el;
    }
    sort(v.begin(), v.end());

    int ans = 1;

    while(true){
        vector<int> tmp;
        for (auto it = v.begin()+1; it < v.end(); ++it){
            if (*it % v[0] != 0) tmp.push_back(*it);
        }
        if (tmp.size() == 0) break;
        else if (tmp.size() == 1){
            ans += 1;
            break;
        }
        else {
            ans += 1;
            v.swap(tmp);
        }
    }

    cout << ans << endl;

    return 0;
}

// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &el: v) {
            cin >> el;
        }

        set<int> a(v.begin(), v.end());
        int ans = -1;
        if (!a.empty()){
            for (auto el: a){
                int cnt = count(v.begin(), v.end(), el);
                if (cnt == 1){
                    auto found = find(v.begin(), v.end(), el);
                    ans = distance(v.begin(), found) + 1;
                    break;
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}

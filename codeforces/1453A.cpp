// 

#include <iostream>
#include <algorithm>
#include <set>


using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        set<int> b, l;
        int tmp;
        for (int i=0; i<n; ++i) {
            cin >> tmp;
            b.insert(tmp);
        }
        for (int i=0; i<m; ++i) {
            cin >> tmp;
            l.insert(tmp);
        }

        int ans = 0;
        for (auto el: b){
            if (l.find(el) != l.end()) ++ans;
        }

        cout << ans << endl;

    }

    return 0;
}

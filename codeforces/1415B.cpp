// B. Repainting Street

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        set<int> st;

        for (auto &el: a) {
            cin >> el;
            st.insert(el);
        }

        int ans = numeric_limits<int>::max();

        if (st.size() == a.size()){
            ans = ((n - 1) + k - 1) / k;
        }
        else {
            for (auto num: st){
                int curAns = 0;
                int i = 0;
                while (true){
                    if (i > n-1) break;
                    auto found = find_if_not(a.begin()+i, a.end(), [num](int x){return x==num;});
                    if (found != a.end()){
                        ++curAns;
                        i += distance(a.begin()+i, found);
                    }
                    i += k;
                }
                if (curAns < ans) ans = curAns;
            }
        }

        cout << ans << endl;

    }

    return 0;
}

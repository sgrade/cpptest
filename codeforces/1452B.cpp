// B. Toy Blocks
// NOT FINISHED

#include <iostream>
#include <algorithm>

using namespace std;
using ull = unsigned long long;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        ull a[n];
        for (auto &el: a) cin >> el;
        sort(a, a+n);

        
        ull ans = 0;
        
        if (n > 2){
            for (int i=0; i<n; ++i){
                ull diff = 0;
                for (int j=0; j<n-1; ++j){
                    if (i == j) continue;
                    else{
                        ull tmpDiff = a[n-1] - a[j];
                        ull rem = a[i] - tmpDiff;
                        if (rem < 0) diff += labs(rem);
                        else if (rem > 0){
                            diff += rem % (n - 1);
                        }
                    }
                }
                if (diff > ans) ans = diff;
            }
        }
        
        cout << ans << endl;

    }

    return 0;
}

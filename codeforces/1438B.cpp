// B. Valerii Against Everyone
// NOT FINISHED

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;
using ull = unsigned long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool ans = false;

        vector<ull> b(n), a(n);
        ull tmp;

        for (int i = 0; i<n; ++i){
            cin >> tmp;
            if (!ans){
                auto found = find(b.begin(), b.end(), tmp);
                if (found != b.end()){
                    ans = true;
                }
                else {
                    a[i] = powl(2, tmp);
                }
            }
        }

        if (!ans){
            ull sumLeft, sumRight;
            int l1=0, r1=0, l2=1, r2=1;
            for (l1 = 0; !ans & l1 < n - 1; ++l1){
                for (r1 = l1; !ans && r1 < n - 1; ++r1){
                    sumLeft = accumulate(a.begin()+l1, a.begin()+r1+1, 0);
                    for (l2 = r1 + 1; !ans && l2 < n; ++l2){
                        for (r2 = l2; !ans && r2 < n; ++r2){
                            sumRight = accumulate(a.begin()+l2, a.begin()+r2+1, 0);
                            if (sumLeft == sumRight){
                                ans = true;
                            }
                        }
                    }
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}

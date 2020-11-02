// C. Division
// TLE

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        long long p, q;
        cin >> p >> q;

        int ans = 0;

        if (p < q){
            ans = p;
        }
        /*
        else if (p == q){
            ans = p - 1;
        }
        */
        // p > q
        else {
            long long candidate;
            bool found = false;

            if (q < p) {
                ans = q;
            }
            else if (p % q != 0){
                ans = p;
                found = true;
            }
            else{

            }

            
        }

        cout << ans << endl;

    }

    return 0;
}

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

            if (p % q != 0){
                ans = p;
                found = true;
            }

            while (!found){
                for (long long i = 2; i < p+1; ++i){

                    if (i < q && q % i != 0){
                        if (p % i == 0){
                            ans = max(p / i, i);
                            found = true;
                            break;
                        }
                    }

                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}

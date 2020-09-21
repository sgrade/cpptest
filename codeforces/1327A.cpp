// A. Sum of Odd Integers

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        long long n, k;
        cin >> n >> k;

        bool answer = false;    

        /*
        bool nIsOdd = n%2 == 0 ? false : true;
        bool kIsOdd = k%2 == 0 ? false : true;
        // n is odd
        else if (nIsOdd && kIsOdd) answer = true;
        else if (nIsOdd && !kIsOdd) answer = false;
        // n i even
        else if (!nIsOdd && kIsOdd) answer = false;
        else if (!nIsOdd && !kIsOdd) answer = true;
        */

        // above can be summarized as follows
        // if (n%2 == k%2) answer = true;
        // See arithmetic progression: sum of n first terms
        // else if (k*k <= n) answer = true;

        if (n%2 == k%2 && k*k <=n) answer = true;

        // below not required (already included in k*k)
        // if (k>n) answer = false;

        cout << (answer ? "YES\n" : "NO\n");

    }

    return 0;
}
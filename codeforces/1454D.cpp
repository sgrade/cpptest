// 

#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;
using ull = unsigned long long;


vector<unsigned long long> allPrimeFactors (unsigned long long n){
    vector<unsigned long long> v;
    if (n == 0 || n == 1) return v;

    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for (unsigned long long i=3; i <= sqrtl(n); i += 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }
    
    if (n > 2) v.push_back(n);

    return v;

}

int main(){

    int t;
    cin >> t;

    while(t--){

        ull n;
        cin >> n;

        ull ans = 1;

        vector<ull> v = allPrimeFactors(n);
        ull candidateFactor = n;
        for (auto el: v){
            ull cnt = count(v.begin(), v.end(), el);
            if (cnt > ans) {
                ans = cnt;
                candidateFactor = el;
            }
        }

        cout << ans << endl;

        ull numOfCandidates = count(v.begin(), v.end(), candidateFactor);
        if (numOfCandidates > 1){
            for (int i = 0; i < numOfCandidates - 1; ++i){
                cout << candidateFactor << ' ';
                n /= candidateFactor;
            }
        }
        cout << n << endl;
    }

    return 0;
}

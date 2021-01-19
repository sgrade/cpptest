// 

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
using ull = unsigned long long;


bool isPrime (unsigned long long n){
    if (n == 0 || n == 1) return false;
    for (unsigned long long i=2; i <= sqrtl(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        ull d;
        cin >> d;

        vector<ull> ans = {1};
        ull tmp = 1;
        for (int i = 0; i < 2; ++i){
            tmp += d;
            while (true){
                if (isPrime(tmp)){
                    ans.push_back(tmp);
                    break;
                }
                ++tmp;
            }
        }
        
        cout << ans[1] * ans[2] << endl;

    }

    return 0;
}

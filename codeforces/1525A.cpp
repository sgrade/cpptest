// A. Potion-making

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

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


int main() {

    int t;
    std::cin >> t;

    while (t--) {
        ull k;
        std::cin >> k;

        ull ans;
        
        if (100 % k == 0) {
            ans = 100 / k;
        }

        else {

            ull e = k, w = 100 - k;
            vector<ull> factors_e, factors_w;

            factors_e = allPrimeFactors(e);
            factors_w = allPrimeFactors(w);

            vector<ull> common_elements;
            set_intersection(
                factors_e.begin(), factors_e.end(),
                factors_w.begin(), factors_w.end(),
                back_inserter(common_elements));

            if (common_elements.size() > 0) {
                for (auto &el: common_elements) {
                    e /= el;
                    w /= el;
                }
            }

            ans = e + w;

        }

        std::cout << ans << std::endl;
    } 

    return 0;
}

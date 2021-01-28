// B. Maximum Product

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        std::cin >> n;
        std::vector<int> v(n);
        for (auto &el: v) std::cin >> el;

        std::sort(v.begin(), v.end());

        long long ans = std::numeric_limits<long long>::min();

        // Key ideas from https://codeforces.com/contest/1406/submission/93622500

        for (int i = 0; i < 5; ++i){
            
            std::vector<int> tmp;
            tmp.insert(tmp.begin(), v.begin(), v.begin()+i);
            tmp.insert(tmp.end(), v.begin()+n-5+i, v.end());
            
            long long p = 1;
            for (auto el: tmp) p *= el;

            ans = std::max(ans, p);
        }
        
        std::cout << ans << std::endl;

    }

    return 0;
}

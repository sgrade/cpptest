// E. Tetrahedron

#include <iostream>

using ull = unsigned long long;


int main() {

    const int MOD = 1e9 + 7;

    int n;
    std::cin >> n;

    // Editorial - https://codeforces.com/blog/entry/4173
    
    // Number of ways to reach D:
    
    // When n == 0
    ull from_D = 1;
    ull from_ABC = 0;
    
    // When n > 0
    ull current_from_D, current_from_ABC;
    for (int i = 1; i <=n; ++i) {
        // Any cycle starts from D
        // from D there is 3 ways: 1) to A; 2) to B; 3) to C
        // so, we came from A or B or C and can go 3 ways
        current_from_D = from_ABC * 3 % MOD;
        
        // A, B, C are equivalent
        // From any of them there are two ways back to D (to complete the cycle)
        current_from_ABC = from_ABC * 2;
        // Take into account previous cycles
        current_from_ABC = current_from_ABC + from_D;
        // MOD
        current_from_ABC %= MOD;

        //
        from_D = current_from_D;
        from_ABC = current_from_ABC;
    }

    std::cout << from_D << std::endl;

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

// The explanation is here - 
// https://www.geeksforgeeks.org/fast-io-for-competitive-programming/


int main() {

    // The below speeds up cin/cout greatly
    // E.g. in 1574C.cpp this is allowed me to reduce time greatly (avoid TLE). 
    // No other ways happened.
    // https://codeforces.com/contest/1574/my
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Why cout.tie(NULL) is not required
    // https://codeforces.com/blog/entry/90775
  
    // Also this
    cout << "USE '\n' instead of endl" << 'n';

    return 0;
}

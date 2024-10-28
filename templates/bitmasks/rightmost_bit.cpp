#include <bits/stdc++.h>

using namespace std;


int main() {

    for (int n = 0; n < 17; ++n) {
        int rightmost_bit = n & (-n);
        cout << n << ": " << rightmost_bit << endl;
    }

    return 0;
}

/* 

0: 0
1: 1
2: 2
3: 1
4: 4
5: 1
6: 2
7: 1
8: 8
9: 1
10: 2
11: 1
12: 4
13: 1
14: 2
15: 1
16: 16

*/
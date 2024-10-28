#include <bits/stdc++.h>

using namespace std;


int main() {

    for (int n = 0; n < 17; ++n) {
        bool not_power_of_two = n & (n - 1);
        cout << n << ": " << not_power_of_two << endl;
    }

    return 0;
}

/* 

0: 0
1: 0
2: 0
3: 1
4: 0
5: 1
6: 1
7: 1
8: 0
9: 1
10: 1
11: 1
12: 1
13: 1
14: 1
15: 1
16: 0

*/
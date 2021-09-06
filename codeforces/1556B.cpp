// B. Take Your Places!
// Wrong answer on pretest 2:
// wrong answer 40th numbers differ - expected: '2', found: '3'

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        int odd = 0, even = 0;
        for (auto &el: a) {
            cin >> el;
            if (el % 2 == 0) {
                ++even;
            }
            else {
                ++odd;
            }
        }

        // n == 1
        int ans = 0;

        if (abs(odd - even) > 1) {
            ans = -1;
        }

        else if (n > 1) {

            vector<int>::iterator cur_it = begin(a), prev_it = begin(a), next_it = begin(a);

            bool cur_parity = (*cur_it) % 2;
            bool prev_parity = cur_parity;
            int d;

            // Checking if the first element is OK
            if (odd != even) {  
                if ((odd > even && cur_parity ==0) || (even > odd && cur_parity != 0)) {
                    next_it = find_if(cur_it + 1, end(a), [prev_parity](int x){
                        return x % 2 != prev_parity;
                    });
                    swap(*cur_it, *next_it);
                    d = distance(cur_it, next_it);
                    ans += d;
                    prev_it = cur_it;
                }
            }

            prev_parity = (*cur_it) % 2;
            
            while (true) {

                cur_it = prev_it + 1;
                int prev_idx = distance(begin(a), prev_it);
                int cur_idx = distance(begin(a), cur_it);
                if (cur_it == end(a)) {
                    break;
                }
                cur_parity = (*cur_it) % 2;

                if (cur_parity == prev_parity) {
                    next_it = find_if(cur_it + 1, end(a), [prev_parity](int x){
                        return x % 2 != prev_parity;
                    });
                    if (next_it == end(a)) {
                        break;
                    }
                    int next_idx = distance(begin(a), next_it);
                    d = distance(cur_it, next_it);
                    ans += d;
                    swap(*cur_it, *next_it);
                }

                prev_it = cur_it;
                prev_parity = (*cur_it) % 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

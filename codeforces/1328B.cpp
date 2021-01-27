// B. K-th Beautiful String

#include <iostream>
#include <string>

using namespace std;
using ll = long long;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        // Visual representation from here helped me understand the pattern
        // https://www.youtube.com/watch?v=bZQDRArWYeI
        
        // Left 'b'
        // Initial position
        int row = 1;
        int left_b_index = n - 2;
        int cycle = 2;     
        // Down the list (see it in the youtube video since 7:00)
        while (row < k) {
            row += cycle;
            --left_b_index;
            ++cycle;
        }

        // Right 'b'
        int right_b_index = n - 1;
        --cycle;
        if (k > 1){
            // the cycle is ariphmetic progression with d = 1 (1, 2, 3, ...)
            // so sum = (1 + n) * n / 2
            // Note: without 1ULL was getting "signed integer overflow" error
            unsigned long long last_row_of_current_cycle = (1 + cycle * 1ULL) * cycle / 2;
            right_b_index = left_b_index + 1 + (last_row_of_current_cycle - k);
        }

        string s(n, 'a');
        s.replace(left_b_index, 1, 1, 'b');
        s.replace(right_b_index, 1, 1, 'b');

        cout << s << endl;
    }


    return 0;
}

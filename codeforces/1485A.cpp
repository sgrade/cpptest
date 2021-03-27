// A. Add and Divide

#include <iostream>
#include <limits>

using namespace std;


int main() {

    int t;
    cin >> t;

    while(t--) {

        int a, b;
        cin >> a >> b;

        int ans = numeric_limits<int>::max();

        bool b_is_one = false;
        if (b == 1) {
            b += 1;
            b_is_one = true;
        }

        // Explanation - https://www.youtube.com/watch?v=BzIc0ZwLvps
        int tmp, current_ans;
        for (int i = 0; i < 31; ++i) {
            tmp = a;
            current_ans = 0;
            if (b_is_one) {
                ++current_ans;
            }

            while (tmp != 0) {
                tmp /= (b + i);
                ++current_ans;
            }
            
            ans = min(ans, current_ans + i);
        }

        cout << ans << endl;

    }

    return 0;
}

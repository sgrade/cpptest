// B. Two Buttons

#include <iostream>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    int ans = 0;
    
    if (m <= n) 
    {
        ans = n - m;
    }

    else 
    {
        // key ideas - https://www.youtube.com/watch?v=_IDe4l7rhzM
        int tmp = m;
        while (tmp > n)
        {
            if (tmp % 2 == 0) {
                tmp /= 2;
            }
            else {
                ++tmp;
            }
            ++ans;
        }
        if (tmp < n)
        {
        ans += n - tmp;
        }
    }

    cout << ans << endl;

    return 0;
}

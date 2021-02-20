// A. Cut Ribbon
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    set<int> lengths;
    lengths.insert(a);
    lengths.insert(b);
    lengths.insert(c);

    int ans = 0;
    bool stop = false;
    int num_x = 0, num_y = 0, num_z = 0, rem_x, rem_y, rem_z;

    for (auto x: lengths) {
        if (stop) break;
        num_x = n / x;
        for(; num_x >=0; --num_x) {
            rem_x = n - num_x * x;
            if (rem_x == 0)
            {
                stop = true;
                break;
            }

            for (auto y : lengths)
            {
                if (stop)
                    break;
                if (y == x || y > rem_x)
                    continue;
                num_y = rem_x / y;
                for(; num_y >=0; --num_y) {
                    rem_y = rem_x - num_y * y;
                    if (rem_y == 0)
                    {
                        stop == true;
                        break;
                    }
                    
                    for (auto z : lengths)
                    {
                        if (stop)
                            break;
                        if (z == x || z == y || rem_y > z)
                            continue;
                        num_z = rem_y / z;
                        for(; num_z >=0; --num_z) {
                            rem_z = rem_y  - num_z * z;
                            if (rem_z == 0)
                            {
                                stop == true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    ans = num_x + num_y + num_z;

    cout << ans << endl;

    return 0;
}

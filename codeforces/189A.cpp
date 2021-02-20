// A. Cut Ribbon

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
    
    for (auto x: lengths) {
        int num_x = 0, num_y = 0, num_z = 0, rem_x, rem_y, rem_z;
        bool stop = false;

        num_x = n / x;
        while(num_x >=0) {
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
                while (num_y >=0) {
                    rem_y = rem_x - num_y * y;
                    if (rem_y == 0)
                    {
                        stop = true;
                        break;
                    }
                    
                    for (auto z : lengths)
                    {
                        if (stop)
                            break;
                        if (z == x || z == y || z > rem_y)
                            continue;
                        num_z = rem_y / z;
                        while(num_z >=0) {
                            rem_z = rem_y  - num_z * z;
                            if (rem_z == 0)
                            {
                                stop = true;
                                break;
                            }
                            if (stop) 
                                break;
                            else 
                                --num_z;
                        }
                    }
                    if (stop)
                        break;
                    else
                        --num_y;
                }
            }

            if (stop) 
                break;
            else
                --num_x;
        }

        ans = max(ans, num_x + num_y + num_z);
    }


    cout << ans << endl;

    return 0;
}

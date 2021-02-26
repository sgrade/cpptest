// A. Vacations

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) cin >> el;

    int ans = 0;
    
    if (n == 1)
    {
        if (a[0] == 0) ans = 1;
    }

    else 
    {
        vector<bool> train(n);
        if (a[0] != 0) train[0] = true;
        for (int i = 1; i < n; ++i)
        {
            if (a[i] != 0) 
            {
                if (!train[i - 1])
                    train[i] = true;

                else if (a[i] == 3) 
                    train[i] = true;

                else if (a[i-1] != 3) {
                    if (a[i] != a[i-1])
                        train[i] = true;
                }

                else // a[i-1] == 3
                {
                    auto rit1 = find_if(a.rbegin()+(n-i), a.rend(), [](int x){
                        return x!= 3;
                    });
                    auto idx1 = distance(a.begin(), rit1.base() - 1);

                    auto rit2 = find_if(train.rbegin() + (n - i), train.rend(), [](bool x) {
                        return !x;
                    });
                    auto idx2 = distance(train.begin(), rit2.base() - 1);

                    if (idx2 >= idx1)
                        train[i] = true;
                    
                    else
                    {
                        if (rit1 == a.rend() || *rit1 == 0)
                            train[i] = true;
                        
                        else 
                        {
                            if ((i - idx1) % 2 == 0)
                            {
                                if (a[idx1] == a[i]) train[i] = true;
                            }
                            else 
                            {
                                if (a[idx1] != a[i]) train[i] = true;
                            }
                        }
                    }
                }
            }
        }
        ans = n - accumulate(train.begin(), train.end(), 0);
    }

    cout << ans << endl;

    return 0;
}

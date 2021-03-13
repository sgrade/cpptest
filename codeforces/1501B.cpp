// B. Napoleon Cake
// Time limit exceeded on pretest 3

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a)
            cin >> el;
        
        vector<bool> drenched(n);
        vector<bool>::reverse_iterator rit;
        int ridx;

        // i = layers
        for (int i = 0; i < n; ++i)
        {           
            if (a[i] > 0)
            {
                int j = max(0, i - a[i] + 1);

                rit = find(drenched.rbegin() + n - i - 1, drenched.rend(), false);

                if (rit == drenched.rend())
                {
                    drenched[i] = true;
                }
                else
                {   
                    ridx = distance(drenched.begin(), rit.base());
                    for (; j < ridx; ++j)
                        drenched[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i)
            cout << drenched[i] << ' ';
        cout << endl;
    }

    return 0;
}

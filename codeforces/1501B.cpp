// B. Napoleon Cake

#include <iostream>
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
        
        vector<int> drenched(n);

        // i = layers
        int layers_drenched = 0;
        for (int i = n - 1; i > -1; --i)
        {           
            // Idea - https://codeforces.com/contest/1501/submission/109925625
            layers_drenched = max(layers_drenched - 1, a[i]);
            if (layers_drenched > 0)
                drenched[i] = 1;
        }

        for (int i = 0; i < n; ++i)
            cout << drenched[i] << ' ';
        cout << endl;
    }

    return 0;
}

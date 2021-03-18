// A. Domino on Windowsill

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--)
    {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2;
        cin >> w >> b;

        int white_dominos = min(k1, k2);
        int white_one_line = abs(k1 - k2);
        int black_dominos = n - max(k1, k2);

        bool ans = false;
        if (white_dominos + white_one_line / 2 >= w)
        {
            if (black_dominos + white_one_line / 2 >= b)
            {
                ans = true;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}

// A. Space Navigation

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {
        int px, py;
        cin >> px >> py;

        string s;
        getline(cin >> ws, s);

        int u, d, r, l;
        u = count(s.begin(), s.end(), 'U');
        d = - count(s.begin(), s.end(), 'D');
        r = count(s.begin(), s.end(), 'R');
        l = - count(s.begin(), s.end(), 'L');

        bool ans = false;
        if (px == 0 || (0 < px && px <= r) || (l <= px && px < 0)){
            if (py == 0 || (0 < py && py <= u) || (d <= py && py < 0)){
                ans = true;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}

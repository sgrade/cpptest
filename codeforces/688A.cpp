// A. Opponents

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n, d;
    cin >> n >> d;

    int days[d];
    fill_n(days, d, 1);
    
    for (int i = 0; i < d; ++i){
        string s;
        getline(cin >> ws, s);
        for (auto ch: s) {
            if (ch == '0') days[i] = 0;
        }
    }

    int ans = 0, cur = 0;
    for (auto day: days){
        if (day == 1) cur = 0;
        else {
            cur += 1;
            if (cur > ans) ans = cur;
        }
    }

    cout << ans << endl;

    return 0;
}

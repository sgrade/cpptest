// B. Tavas and SaDDas

#include <iostream>
#include <string>

using namespace std;


int main(){

    // Complex solution, but good insights - https://www.youtube.com/watch?v=-D5Hb5MoiM4

    // Editorial - https://codeforces.com/blog/entry/17401
    // The best (simple and elegant) of what I found - https://ideone.com/0fX8LQ (the latest solution mentioned in the editorial)

    string s;
    cin >> s;

    int ans = 1;

    for (int i=0; i<s.size(); ++i){
        ans = 2 * ans;

        int num = (int)s[i] - 48;
        if (num == 7) ++ans;
        // cout << num << ' ' << ans << endl;
    }
    ans -= 1;

    cout << ans << endl;

    return 0;
}
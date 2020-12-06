// 

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        int cnt = count(s.begin(), s.end(), 'r');

        string ans = "";
        for (int i = 0; i < cnt; ++i) ans += 'r';
        for (int i = 0; i < n; ++i){
            if (s[i] != 'r') ans += s[i];
        }

        cout << ans << endl;

    }

    return 0;
}

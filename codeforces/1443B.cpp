// B. Saving the City

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;

        string s;
        getline(cin >> ws, s);

        int ans = 0;

        vector<char> v(s.begin(), s.end());
        int ones = count(v.begin(), v.end(), '1');     

        if (ones != 0){
            auto fpos = find(v.begin(), v.end(), '1');
            if (fpos != v.end()){
                v.erase(v.begin(), fpos);
            }
            reverse(v.begin(), v.end());
            auto fpos1 = find(v.begin(), v.end(), '1');
            if (fpos1 != v.end()){
                v.erase(v.begin(), fpos);
            }
            
            int zeros = count(v.begin(), v.end(), '0');

            ans = min(ones * a, zeros * (a+b));
        }

        cout << ans << endl;

    }

    return 0;
}

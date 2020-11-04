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

        s.erase(0, s.find('1'));
        s.erase(s.find_last_of('1')+1);

        int sSize = s.size();
        if (sSize > 0){    
            ans += a;
            
            // https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
            size_t pos = 0;
            string token;
            while((pos = s.find('1')) != string::npos){
                token = s.substr(0, pos);
                ans += min(a, b * (int)token.size());
                s.erase(0, pos + 1);
            }
        }

        cout << ans << endl;

    }

    return 0;
}

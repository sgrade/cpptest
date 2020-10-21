// A. Telephone Number

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        bool ans = false;
        if (s.size()>10){
            string tmp = s.substr(0, n-10);
            size_t found = tmp.find('8');
            if (found != string::npos){
                ans = true;
            }
        }

        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
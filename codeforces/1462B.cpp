// B. Last Year's Substring

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

        bool ans = false;

        string target = "2020";

        for (int i = 0; i < 5; ++i){
            string first = s.substr(0, i);
            string last = s.substr(n-4+i, 4-i);
            if (s.substr(0, i) == target.substr(0, i) && s.substr(n-4+i, 4-i) == target.substr(i, 4-i)){
                ans = true;
                break;
            }
        }

        
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}

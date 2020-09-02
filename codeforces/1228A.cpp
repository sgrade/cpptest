// A. Distinct Digits

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int l, r;
    cin >> l >> r;

    string s;
    string output = "-1";
    for (int i=l; i<=r; ++i){

        s = to_string(i);
        
        bool duplicate = false;
        for (int j=0; j<s.size(); ++j){
            if (count(s.begin(), s.end(), s[j]) > 1){
                duplicate = true;
                break;
            }
        }
        if (!duplicate){
            output = s;
        }
    }

    cout << output << endl;

    return 0;
}
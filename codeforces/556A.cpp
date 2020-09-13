// A. Case of the Zeros and Ones

#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    int output = 0;
    if (s.size()==1){
        output = 1;
    }
    else {
                
        /*
        char prev = s[0];
        char cur;
        for (int i=1; i<n; ++i){
            cur = s[i];
            if (cur == prev){
                ++output;
            }
            else {
                if (i!=n-1){
                    ++i;
                }
            }
            prev = s[i];
        }
        */
    }

    cout << output << endl;

    return 0;
}
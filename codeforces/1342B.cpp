// B. Binary Period

#include <iostream>
#include <bitset>

using namespace std;


int main(){

    int T;
    cin >> T;

    while(T--){

        string t;
        getline(cin >> ws, t);

        // Editorial - https://codeforces.com/blog/entry/76633
        int zeroes = 0, ones = 0;
        for (int i=0; i<t.size(); ++i){
            if (t[i] == '0') ++zeroes;
            else ++ones;
        }

        if (zeroes == t.size() || ones == t.size()){
            cout << t << endl;
        }
        else {
            for (int i=0; i<2*t.size(); i+=2){
                cout << "01";
            }
            cout << endl;
        }

    }

    return 0;
}
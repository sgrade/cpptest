// B. Borze

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    cin >> s;

    bool prevChar = false;
    for (int i=0; i<s.size(); ++i){
        if (s[i]=='.' && prevChar==false){
            cout << 0;
            continue;
        }
        else if (prevChar == false){
            prevChar = true;
            continue;
        }
        else if (s[i]=='.' && prevChar==true){
            cout << 1;
            prevChar = false;
            continue;
        }
        else {
            cout << 2;
            prevChar = false;
        }
    }
    
    return 0;
}
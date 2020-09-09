// A. Chat room

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


int main(){

    string s;
    cin >> s;

    string hello = "hello";
    string output;
    
    int j=0;
    for (int i=0; i<hello.size(); ++i){
        while(j<s.size()){
           if (hello[i] == s[j]) {
               output += s[j];
               ++j;
               break;
           }
           else {
               ++j;
           }
        }
    }

    if (output == hello){
            cout << "YES\n";
    }
    else cout << "NO\n";

    return 0;
}
// A. cAPS lOCK

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    cin >> s;

    bool firstLow = islower(s[0]);

    bool allExceptFirstUpper = true;
    if (s.size()>1){
        for (int i=1; i<s.size(); ++i){
            if (islower(s[i])){
                allExceptFirstUpper = false;
            }
        }
    }
    
    if (firstLow && allExceptFirstUpper){
        s[0] = toupper(s[0]);
    }
    if (!firstLow && allExceptFirstUpper){
        s[0] = tolower(s[0]);
    }
    if (allExceptFirstUpper){
        if (s.size()>1){
            for (int i=1; i<s.size(); ++i){
                s[i] = tolower(s[i]);
            }
        }
    }
    
    cout << s << endl;

    return 0;
}
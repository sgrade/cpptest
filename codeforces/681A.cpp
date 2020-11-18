// A. A Good Contest

#include <iostream>
#include <string>

using namespace std;


int main(){

    bool ans = false;
    
    int n;
    cin >> n;

    while(n--){
        
        string s;
        cin >> s;
        
        int b, c;
        cin >> b >> c;

        
        if (2400 <= b and b < c){
            ans = true;
            break;
        }

    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}

// A. Three Strings

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        string a, b, c;
        cin >> a >> b >> c;

        // if c[i] == a[i], we can swap c[i] and b[i], so a[i]==b[i]
        bool notPossible = false;
        for (int i=0; i<c.size(); ++i){
            if (c[i]!=a[i] && c[i]!=b[i]) {
                notPossible = true;
                break;
            }
        }

        cout << (notPossible ? "NO" : "YES") << endl;

    }

    return 0;
}
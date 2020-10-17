// B. Belted Rooms

#include <iostream>
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

        char ccwEdge = s[n-1];
        char cwEdge = s[0];

        int returnable = 0;
        int tmp = 0;

        bool cwPathOpen = true;
        bool ccwPathOpen = true;
        
        for (int i=0; i<n; ++i){
            if (ccwEdge == '-' || cwEdge == '-') {
                ++returnable;
            }
            if (ccwEdge != '-' || cwEdge != '-') {
                if (ccwEdge == '>'){
                    ccwPathOpen = false;
                }
                if (cwEdge == '<'){
                    cwPathOpen = false;
                }      
            }
            cwEdge = s[i+1];
            ccwEdge = s[i];
        }

        if (cwPathOpen || ccwPathOpen) returnable = n;

        cout << returnable << endl;

    }

    return 0;
}
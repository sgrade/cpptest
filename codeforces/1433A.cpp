// A. Boring Apartments


#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        string s;
        getline(cin >> ws, s);
        
        int x = (int)s[0] - 48;

        int digits = (x-1)*10;
        int xSize = s.size();
        for (int i=xSize; i>0; --i){
            digits += i;
        }

        cout << digits << endl;

    }

    return 0;
}
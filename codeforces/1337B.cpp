// B. Kana and Dragon Quest game

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        
        int x, n, m;
        cin >> x >> n >> m;

        bool dragonDefeated = false;
        
        while (n-- && x >10){
            x = x/2+10;
        }

        dragonDefeated = x-10*m <= 0 ? true : false;

        cout << (dragonDefeated ? "YES\n" : "NO\n");

    }
    
    return 0;

}
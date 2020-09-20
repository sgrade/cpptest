// B. 01 Game

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        string s;
        getline(cin >> ws, s);

        char movedLast = 'B';

        if (s.size()>1){
            int sInitialSize = s.size()/2;
            bool movePossible = true;
            // No way there will be more moves than s.size()/2
            for (int i=0; s.size()>1 && movePossible; ++i){
                // Player tries to move
                for (int j=1; j<s.size(); ++j){
                    if (s[j]!=s[j-1]){
                        s.erase(j-1, 2);
                        movedLast = i%2==0 ? 'A' : 'B';
                        break;
                    }
                    else if (j==s.size()-1){
                        movePossible = false;
                    }
                }
            }
                
        }

        cout << (movedLast == 'A' ? "DA\n" : "NET\n");

    }

    return 0;
}
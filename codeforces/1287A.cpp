// A. Angry Students

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int k;
        cin >> k;

        string s;
        cin >> s;

        int minutes = 0, maxMinutes = 0;
        char prev=s[0];
        bool counting = false;

        if (k>1){
            for (int i=1; i<k; ++i){
                if (prev=='A' && s[i]=='P') 
                {
                    counting = true;
                }
                else if (prev=='P' && s[i]=='P' && counting) 
                {
                    counting = true;
                }
                else
                {
                    counting = false;
                }

                if (counting)
                {
                    ++minutes;
                    if (minutes>maxMinutes)
                    {
                        maxMinutes = minutes;
                    }
                }
                else
                {
                    minutes = 0;
                }
                

                prev = s[i];
            }
        }

        cout << maxMinutes << endl;

    }

    return 0;
}
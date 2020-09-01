// A. Juggling Letters

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string tmp, s;
        for (int i=0; i<n; ++i){
            cin >> tmp;
            s += tmp;
        }
       
        bool answer = false;
        
        if (s.size()==1) 
            answer = true;
        
        else {
            set<char> st(s.begin(), s.end());

            for (auto ch: st){
                int num = count(s.begin(), s.end(), ch);
                if (num%n != 0) {
                    answer = false;
                    break;
                }
                else answer = true;
            }    
        }

    cout << (answer ? "YES" : "NO") << endl;
    }

    return 0;
}
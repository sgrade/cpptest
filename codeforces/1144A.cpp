// A. Diverse Strings

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    while(n--){
        string s;
        getline(cin >> ws, s);

        bool ans = true;
        
        if (s.size()>1){
            
            sort(s.begin(), s.end());
            
            set<char> st;
            st.insert(s[0]);

            int diff = 0;

            for (int i=1; i<s.size(); ++i){
                st.insert(s[i]);
                
                diff += (int)s[i] - int(s[i-1]);
            }

            if (s.size() != st.size() || diff != s.size()-1) ans = false;
        }
        
        cout << (ans ? "Yes\n" : "No\n");


    }

    return 0;
}

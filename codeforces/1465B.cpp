// B. Fair Numbers

#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ull = unsigned long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        ull n;
        cin >> n;

        ull x = n;
              
        bool flag = true;
        while (flag) {

            set<ull> st;
            while (n > 0){
                st.insert(n % 10);
                n /= 10;
            }
            if (*st.begin() == 0) st.erase(0);

            set<ull>::iterator it;
            for (it = st.begin(); it != st.end(); ++it) {
                if (x % *it != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag && it == st.end()) break;
            else {
                flag = true;
                ++x;
                n = x;
            }
        }

        cout << x << endl;
    }
    
    return 0;
}

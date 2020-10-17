// C. ABBB

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        string s;
        getline(cin >> ws, s);

        int ans = 0;

        if (s.size() == 1){
            ans = 1;
        }
        else {
            
            // Erase trailing As
            std::size_t lastB = s.find_last_of('B');
            if (lastB == string::npos){
                ans += s.size();
                s.clear();                
            }
            else {
                ans += s.size()-1 - lastB;
                s.erase(lastB + 1);
            }

            // Erase pairs of leading Bs
            bool firstB = false;
            if (!s.empty()){

                std::size_t firstA = s.find('A');
                
                if (firstA == string::npos) {
                    ans += s.size() % 2;
                    s.clear();
                }
                else if (firstA != 0){
                    if (firstA % 2 != 0) {
                        s.erase(0, firstA-1);
                    }
                    else {
                        s.erase(0, firstA);
                    }
                }
                
            }

            // Calculating the answer
            // Editorial - https://codeforces.com/blog/entry/83771
            stack<int> stk;
            for (int i=0; i<s.size(); ++i){
                if (s[i] == 'A'){
                    stk.push(s[i]);
                }
                else {
                    if (stk.empty()){
                        stk.push(s[i]);
                    }
                    else stk.pop();
                }
            }

            ans += stk.size();
            
        }

        cout << ans << endl;

    }

    return 0;
}
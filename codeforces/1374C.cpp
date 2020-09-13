// C. Move Brackets

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        // std::ws discards leading whitespaces
        getline(cin >> std::ws, s);

        int moves = 0;

        stack<char> st;
        for (int i=0; i<n; ++i){
            if (s[i] == '('){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else ++moves;
        }

        cout << moves << endl;
    }

    return 0;
}
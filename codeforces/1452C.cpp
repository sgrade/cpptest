// C. Two Brackets

#include <iostream>
#include <string>
#include <stack>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        string s;
        getline(cin >> ws, s);

        stack<char> rnd;
        stack<char> square;

        int ans = 0;
        for (auto ch: s){
            if (ch == '(') rnd.push(ch);
            else if (ch == '[') square.push(ch);
            else if (ch == ')' && !rnd.empty()) {
                rnd.pop();
                ++ans;
            }
            else if (ch == ']' && !square.empty()) {
                square.pop();
                ++ans;
            }
        }

        cout << ans << endl;

    }

    return 0;
}

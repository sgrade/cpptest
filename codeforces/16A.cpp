// A. Flag

#include <iostream>
#include <set>
#include <string>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    bool ans = true;

    int tmp[n];

    string s;
    for (int i = 0; i < n; ++i){
        getline(cin >> ws, s);
        set<char> st(s.begin(), s.end());
        if (st.size() > 1){
            ans = false;
            break;
        }
        else tmp[i] = *st.begin();
    }

    if (n > 1 && ans){
        for (int i = 1; i < n; ++i){
            if (tmp[i] == tmp[i-1]){
                ans = false;
                break;
            }
        }
    }

    cout << (ans ? "YES": "NO") << endl;

    return 0;
}

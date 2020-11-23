// A. Tom Riddle's Diary

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    set<string> st;
    while(n--){
        string s;
        getline(cin >> ws, s);
        if (find(st.begin(), st.end(), s) != st.end()){
            cout << "YES" << endl;
        }
        else {
            st.insert(s);
            cout << "NO" << endl;
        }
    }

    return 0;
}

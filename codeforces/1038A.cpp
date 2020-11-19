// A. Equality

#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    string s;
    getline(cin >> ws, s);

    set<char> st(s.begin(), s.end());

    int ans = 0;

    if (st.size() == k){
        int minOccurences = 100001;
        for (auto letter: st){
            int cnt = count(s.begin(), s.end(), letter);
            if (cnt < minOccurences) minOccurences = cnt;
        }
        ans = minOccurences * k;
    }

    cout << ans << endl;

    return 0;
}

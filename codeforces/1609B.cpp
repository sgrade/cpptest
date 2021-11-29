// B. William the Vigilant

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int check(vector<char> &abc, int &i) {
    int cnt = 0;
    for (int pos = i - 2; pos < i+1; ++pos) {
        cnt += abc[pos] == 'a' && abc[pos+1] == 'b' && abc[pos+2] == 'c';
    }
    return cnt;
}


int main() {

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<char> abc(begin(s), end(s));

    int cnt_abc = 0;
    int pos = 0;
    while (true) {
        pos = s.find("abc", pos);
        if (pos != string::npos) {
            ++cnt_abc;
            pos += 3;
        }
        else {
            break;
        }
    }

    vector<int> ans(q);

    int i;
    char c;
    bool prev, cur;
    
    for (int j = 0; j < q; ++j) {

        cin >> i >> c;
        --i;

        // Inspiration for the implementation 
        // https://codeforces.com/contest/1609/submission/137222999
        cnt_abc -= check(abc, i);
        abc[i] = c;
        cnt_abc += check(abc, i);
        
        ans[j] = cnt_abc;
    }

    for (auto &el: ans) {
        cout << el << '\n';
    }

    return 0;
}

// B. Nezzar and Lucky Number
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


// Check if dch is lucky
bool isLucky (string s, char dch){
    bool lucky = false;
    for (int j = 0; j < s.size(); ++j){
        if (s[j] == dch) {
            lucky = true;
            break;
        }
    }
    return lucky;
}

// All lucky numbers up to 110
vector<int> allLucky (int a, int d){
    vector<int> lucky;
    
    int tmp = d;
    while (tmp < a){
        lucky.push_back(tmp);
        tmp += 10;
    }
    tmp = d * 10;
    for (int k = 1; tmp < a && k < 11; ++k){
        lucky.push_back(tmp);
        ++tmp;
    }
    if (100 + d < a) {
        lucky.push_back(100 + d);
        if (d == 1) lucky.push_back(100);
    }
    
    for (auto el: lucky) cout << el << ' ';

    return lucky;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int q, d;
        cin >> q >> d;

        vector<int> v;
        for (auto &el: v) cin >> el;
        
        vector<int> lucky = allLucky(q, d);
        char dch = '0' + d;

        string s;
        for (int a: v){
            int ans = false;

            if (a > 109){
                ans = true;
            }

            else {
                s = to_string(a);

                ans = isLucky(s, dch);

                if (!ans) {
                    vector<int> lucky;
                    int tmp = d;
                    
                    

                    for (int j = lucky.size() - 1; j >= 0; ++j){

                    }
                }
            }

            cout << (ans ? "YES" : "NO") << endl;
        }
    }

    return 0;
}

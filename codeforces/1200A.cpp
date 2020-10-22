// A. Hotelier

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    vector<int> v(10, 0);

    for (int i=0; i<s.size(); ++i){
        if (s[i] == 'L'){
            vector<int>::iterator it;
            it = find(v.begin(), v.end(), 0);
            *it = 1;
        }
        else if (s[i] == 'R'){
            vector<int>::reverse_iterator rit;
            rit = find(v.rbegin(), v.rend(), 0);
            *rit = 1;
        }
        else {
            int index = (int)s[i] - 48;
            v[index] = 0;
        }
    }

    for (auto it: v) cout << it;
    cout << endl;

    return 0;
}

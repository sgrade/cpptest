// B. Two-gram

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    map<string, int> mp;

    for (int i = 1; i < n; ++i){
        string tmp(s.begin()+i-1, s.begin()+i+1);
        ++mp[tmp];
    }

    int cnt = 0;
    string ans = "";
    for (auto el: mp){
        if (el.second > cnt){
            cnt = el.second;
            ans = el.first;
        }
    }

    cout << ans << endl;

    return 0;
}

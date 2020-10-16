// A. Silent Classroom

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){

    int n;
    cin >> n;

    map<char, int> mp;

    int ans = 0;

    string s;
    for (int i=0; i<n; ++i){
        getline(cin >> ws, s);
        ++mp[s[0]];
    }

    for (auto it: mp){
        // https://www.geeksforgeeks.org/find-ceil-ab-without-using-ceil-function/
        // ceil: (a + b - 1) / b
        // studentsInOneRoom: 
        int room1 = (it.second + 2 - 1) / 2;
        int room2 = (it.second) / 2;
        // number of combinations - https://en.wikipedia.org/wiki/Combination
        // combinations formula is simplified, taking into account that k = 2
        // so (n! / (n-2)!) is simplified to (n*(n-1))
        ans += room1*(room1-1) / 2;
        ans += room2*(room2-1) / 2;
    }

    cout << ans << endl;

    return 0;
}
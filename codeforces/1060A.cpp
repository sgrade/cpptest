// A. Phone Numbers

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    int cnt = count(s.begin(), s.end(), '8');
    int ans = min(cnt, n / 11);

    cout << ans << endl;

    return 0;
}

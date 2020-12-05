// A. Lucky Ticket

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    string num;
    getline(cin >> ws, num);

    bool ans = true;
    set<char> stNum(num.begin(), num.end());
    set<char> st = {'4', '7'};

    ans = includes(st.begin(), st.end(), stNum.begin(), stNum.end());

    if (ans){
        int first = 0;
        for (int i=0; i<n/2; ++i) first += (int)num[i] - 48;
        int second = 0;
        for (int i=n/2; i<n; ++i) second += (int)num[i] - 48;
        if (first != second) ans = false;
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}

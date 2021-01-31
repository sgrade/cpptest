// A. In-game Chat

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        auto good_part = s.find_last_not_of(')');
        ++good_part;

        cout << (n - good_part > good_part ? "Yes" : "No") << endl;

    }

    return 0;
}

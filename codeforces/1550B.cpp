// B. Maximum Cost Deletion

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, a, b;
        cin >> n >> a >> b;

        string s;
        getline (cin >> ws, s);

        // Editorial - https://codeforces.com/blog/entry/92864

        int segments = unique(begin(s), end(s)) - begin(s);

        // max l is n
        int fixed_part = a * n;
        // either delete char by char OR segment by segment
        int variable_part = max(b * n, b * (segments/2 + 1));
        
        int ans = fixed_part + variable_part;
        cout << ans << endl;
    }

    return 0;
}

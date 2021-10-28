// G. Fake News (easy)

#include <iostream>
#include <string>

using namespace std;


int main() {

    string s;
    cin >> s;

    bool ans = false;

    int n = size(s);

    string fake = "heidi";
    int j = 0;

    for (int i = 0; i < n; ++i) {
        
        if (s[i] == fake[j]) {
            ++j;
        }

        if (j == 5) {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}

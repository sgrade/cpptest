// C. Ternary XOR

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        string s, s1, s2;
        getline(cin >> ws, s);

        // Editorial - https://codeforces.com/blog/entry/75246
        for (int i = 0; i < n; ++i){
            if (s[i] == '1') {
                s1 += '1';
                s2 += '0';
                for (int j = i + 1; j < n; ++j) {
                    s1 += '0';
                    s2 += s[j];
                }
                break;
            }
            else {
                if (s[i] == '2') {
                    s1 += '1';
                    s2 += '1';
                }
                else {
                    s1 += '0';
                    s2 += '0';
                }
            }
        }
        
        cout << s1 << endl << s2 << endl;

    }

    return 0;
}

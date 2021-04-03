// A. Déjà Vu

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        string s;
        getline(cin >> ws, s);

        auto found1 = find_if_not(s.begin(), s.end(), [](char c){
            return c == 'a';
        });
        
        if (found1 == s.end()) {
            cout << "NO" << endl;
        }

        else {
            cout << "YES" << endl;
            
            auto found2 = find_if_not(s.rbegin(), s.rend(), [](char c){
                return c == 'a';
            });

            int d1 = distance(s.begin(), found1);
            int d2 = distance(s.rbegin(), found2);
            if (d1 >= d2) {
                cout << 'a' << s << endl;
            }
            else {
                cout << s << 'a' << endl;
            }
        }

    }



    return 0;
}

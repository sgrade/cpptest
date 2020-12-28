// A. Regular Bracket Sequence

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    while(n--){
        string s;
        getline(cin >> ws, s);

        bool ans = false;

        auto openIndex = s.find('(');
        auto closeIndex = s.find(')');

        if (openIndex < closeIndex){
            if ((s.size() - 2) % 2 == 0) ans = true;
        }
        else if (closeIndex > 0 && openIndex < s.size() - 1){
            if (s.size() == 4 || (s.size() - 4) % 2 == 0) ans = true;
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}

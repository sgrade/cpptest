// B. Keyboard Layouts

#include <iostream>
#include <string>

using namespace std;

int main(){

    string l1, l2, s, ans;
    getline(cin, l1);
    getline(cin, l2);
    getline(cin, s);

    for (int i=0; i<s.size(); ++i){
        size_t ind = l1.find(tolower(s[i]));
        if (ind == string::npos) {
            ans += s[i];
        }
        else{
            bool isLow = islower(s[i]);
            isLow ? ans += l2[ind] : ans += toupper(l2[ind]);
        }
    }

    cout << ans << endl;

    return 0;
}

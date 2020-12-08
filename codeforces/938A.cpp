// A. Word Correction

#include <iostream>
#include <string>

using namespace std;


int main(){

    string vowels = "aeiouy";
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i){
        if (vowels.find(s[i]) != string::npos){
            if (vowels.find(s[i+1]) != string::npos) {
                s.erase(s.begin()+i+1);
                --i;
            }
            else ++i;
        }
    }

    cout << s << endl;

    return 0;
}

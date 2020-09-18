// A. Keyboard

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<string> v = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};

    char tmp;
    cin >> tmp;
    int shift = tmp=='R' ? -1 : 1;

    string s;
    getline(cin >> ws, s);

    for (int i=0; i<s.size(); ++i){
        
        for (int j=0; j<3; ++j){
            size_t index = v[j].find(s[i]);

            if (index != string::npos){
            
                // last element - no way we can go right
                if (index == 9 && shift == 1) index = 9;
                // first element - no way we can go left
                else if (index == 0 && shift == -1) index = 0;
                // anything else
                else index += shift;
                
                cout << v[j][index];

                break;
            }
        }
    }
    cout << endl;

    return 0;
}
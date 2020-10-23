// A. Suffix Three

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    map<string, string> mp = {
        {"po", "FILIPINO"},
        {"desu", "JAPANESE"},
        {"masu", "JAPANESE"},
        {"mnida", "KOREAN"}
    };

    while(t--){

        string s;
        getline(cin >> ws, s);

        for (auto it: mp){
            auto found = s.rfind(it.first);
            if (found != string::npos && (found == s.size() - it.first.size())){
                cout << it.second << endl;
                break;
            }
        }

    }

    return 0;
}
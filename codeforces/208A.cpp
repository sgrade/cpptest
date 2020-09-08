// A. Dubstep

#include <iostream>
#include <string>

using namespace std;


int main(){

    string s;
    cin >> s;

    while (true){

        int pos = s.find("WUB");
        if (pos != string::npos){
            if (pos != 0) {
                cout << s.substr(0, pos) + " ";
            }
            s.erase(0, pos+3);
        }
        else {
            if (s.size() != 0){
                cout << s;
            }
            break;
        }
    }

    cout << endl;

    return 0;
}
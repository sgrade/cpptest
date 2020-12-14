// A. Find Square

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < n; ++i){
        getline(cin >> ws, s);
        auto found = s.find('B');
        if (found != string::npos){
            auto rfound = s.rfind('B');
            int c = (rfound - found) / 2 + 1;

            cout << i + c << ' ' << found + c << endl;
            break;
        }
    }

    return 0;
}

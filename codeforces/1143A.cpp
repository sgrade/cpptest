// A. The Doors

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    char tmp;
    for (int i = 0; i < n; ++i){
        cin >> tmp;
        s.push_back(tmp);
    }

    cout << min(s.rfind('1'), s.rfind('0')) + 1 << endl;

    return 0;
}

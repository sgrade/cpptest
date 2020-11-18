// A. Summer Camp

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    for (int i = 1; i < n + 1; ++i){
        s += to_string(i);
    }

    cout << s[n-1] << endl;

    return 0;
}

// A. Rounding

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string nStr = to_string(n);
    int last = (int)nStr[nStr.size()-1] - 48;

    if (last == 0) cout << n << endl;
    else {
        if (last < 5) cout << n - last << endl;
        else cout << n + (10 - last);
    }

    return 0;
}

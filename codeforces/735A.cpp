// A. Ostap and Grasshopper

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n, k;
    cin >> n >> k;

    string s;
    getline(cin >> ws, s);

    int g = s.find('G');
    int t = s.find('T');

    if (abs(g - t) % k == 0){
        int sign = g < t ? 1 : -1;
        while (g != t){
            if (s[g] == '#') break;
            g += sign * k;
        }
    }

    cout << (g == t ? "YES" : "NO") << endl;

    return 0;
}

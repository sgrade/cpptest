// A. Scarborough Fair

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    string s;
    getline(cin >> ws, s);
    // char a[n] = (s.begin(), s.end());

    for (int i = 0; i < m; ++i){
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for (int x = l-1; x < r; ++x){
            if (s[x] == c1) s[x] = c2;
        }
    }

    cout << s << endl;

    return 0;
}

// A. Coder

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    int ans = n / 2;
    if (n % 2 == 0) {
        ans *= n;
    }
    else{
        ans *= n - 1;
        ans += n;
    }

    cout << ans << endl;

    bool c = true;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (c) cout << 'C';
            else cout << '.';
            c = !c;
        }
        cout << endl;
        if (n % 2 == 0) c = !c;
    }

    return 0;
}

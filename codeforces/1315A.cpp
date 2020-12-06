// A. Dead Pixel

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        x = max(a-(x+1), x);
        y = max(b-(y+1), y);

        int ans = max(x * b, y * a);
        cout << ans << endl;
    }

    return 0;
}

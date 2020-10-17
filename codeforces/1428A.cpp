// A. Box is Pull

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int ans = 0;

        ans += abs(x2-x1);
        ans += abs(y2-y1);

        if (x1!=x2 && y1!=y2) ans += 2;

        cout << ans << endl;

    }
    
    

    return 0;
}
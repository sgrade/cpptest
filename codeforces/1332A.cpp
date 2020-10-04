// A. Exercising Walk

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int finalX = x-a+b;
        int finalY = y-c+d;

        bool ans = false;
        
        if (((x1 <= finalX && finalX <= x2) && (x1 < x2 || a+b == 0)) &&
            ((y1 <= finalY && finalY <= y2) && (y1 < y2 || c+d == 0))) {
                ans = true;
        }
        
        cout << (ans ? "Yes" : "No") << endl;

    }

    return 0;
}
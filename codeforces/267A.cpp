// A. Subtractions

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){
        int x, y;
        scanf("%d %d\n", &x, &y);

        int ans = 0;
        int remainder;
        while (true){
            if (y < x) swap(y, x);

            ans += y / x;
            remainder = y % x;
            if (remainder > 0){
                y = x;
                x = remainder;
            }
            else break;
        }

        printf("%d\n", ans);
    }

    return 0;
}

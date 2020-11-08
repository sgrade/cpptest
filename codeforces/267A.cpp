// A. Subtractions
// NOT FINISHED

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
        while (y / x + y % x > x)
        {
            ans += y / x;
            y = y / x;
            y += y % x;
        }
        ans += y % x;


        printf("%d\n", ans);
    }

    return 0;
}
// A. Cow and Haybales

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n, d, ans;
        scanf("%d %d\n", &n, &d);

        scanf("%d", &ans);
        int tmp;
        for (int i=1; i<n; ++i){
            scanf("%d", &tmp);
            if (d > 0){
                int x = min(d / i, tmp);
                d -= x * i;
                ans += x;
            }
        }

        scanf("\n");

        printf("%d\n", ans);

    }


    return 0;
}

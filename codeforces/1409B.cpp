// B. Minimum Product

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        long long a, b, x, y, n;
        scanf("%lld %lld %lld %lld %lld\n", &a, &b, &x, &y, &n);

        if (a<b) {
            std::swap (a, b);
            std::swap (x, y);
        }
        if (a==b){
            if (a-x < b-y){
                std::swap (a, b);
                std::swap (x, y);
            }
        }

        long long product=0;

        if ( (a-n)>=x && (b-n)>=y ){
            product = std::min({(a-n)*b, (b-n)*a, (a-n/2)*(b-n/2)});
        }
        else {
            while (n--){
                if ((a-1)*b < (b-1)*a){
                    --a;
                }
                else {
                    --b;
                }
            }
        }
            
        printf("%lld\n", product);

    }

    return 0;
}
// A. Berland Poker

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){
        int n, m, k;
        scanf("%d %d %d\n", &n, &m, &k);

        int maxJ = std::min(n/k, m);
        
        int nextMaxJ = std::min(n/k, (m-maxJ)/(k-1));

        if ((m-maxJ)%(k-1) != 0) nextMaxJ += 1;

        printf("%d\n", maxJ - nextMaxJ);
    }

    return 0;
}
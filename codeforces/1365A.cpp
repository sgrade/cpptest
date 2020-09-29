// A. Matrix Game

#include <stdio.h>
#include <algorithm>
#include <numeric>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n, m;
        scanf("%d %d\n", &n, &m);

        bool rows[n] = {0};
        bool columns[m] = {0};

        int tmp;
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                scanf("%d", &tmp);
                if (tmp == 1) {
                    rows[i] = true;
                    columns[j] = true;
                }
            }
            scanf("\n");
        }

        int freeRowsLeft = n - std::accumulate(rows, rows+n, 0);
        int freeColumnsLeft = m - std::accumulate(columns, columns+m, 0);
        int movesLeft = std::min(freeRowsLeft, freeColumnsLeft);

        bool answer = (movesLeft % 2 == 1);
        if (answer){
            printf("Ashish\n");
        }
        else printf("Vivek\n");

    }

    return 0;
}
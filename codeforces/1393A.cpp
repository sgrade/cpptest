// A. Rainbow Dash, Fluttershy and Chess Coloring

#include <stdio.h>


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){
    
        int n;
        scanf("%d\n", &n);

        // We fill the board from the borders to the center
        // DIAGONAL shows the pattern: 
        // Top-left_to_bottom-right diagonal always filled on even moves
        // E.g. for n = 7 diagonal looks like
        // 2 - 2 - 4 - 4 - 4 - 2 - 2, where 2 - second move, 4 - fourth, ...
        // so the total number of moves is
        printf("%d\n", n/2+1);
    
    }

    return 0;
}
// A. Add Odd or Subtract Even

#include <iostream>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int a, b;
        scanf("%d %d\n", &a, &b);

        int diff = b-a;

        int moves = 0;

        if (diff==0) {
            moves = 0;
        }

        else if (diff>0){
            if (diff%2 == 0){
                moves = 2;
            }
            else moves =1;
        }

        // diff < 0
        else {
            if (diff%2 == 0){
                moves = 1;
            }
            else moves = 2;
        }

        printf("%d\n", moves);

    }

    return 0;
}
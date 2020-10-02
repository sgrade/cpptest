// B. Sequential Nim

#include <stdio.h>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int a[n];
        scanf("%d", &(a[0]));
        for(int i=1; i<n; ++i){
            scanf("%d", &(a[i]));
        }
        scanf("\n");

        bool firstWin = true;
        
        int numOfOnes = std::count(a, a+n, 1);
        if (numOfOnes == n && numOfOnes%2 == 0){
            firstWin = false;
        }
        else if (numOfOnes != n && a[0] == 1){
            int firstOnes = 0;
            for (int i=0; i<n; ++i){
                if (a[i] == 1) ++firstOnes;
                else break;
            }
            if (firstOnes%2 != 0){
                firstWin = false;
            }
        }

        printf("%s\n", (firstWin ? "First" : "Second"));

    }

    return 0;
}
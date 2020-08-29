// A. Captain Flint and Crew Recruitment

#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n;
        scanf("%d\n", &n);

        // Editorial - https://codeforces.com/blog/entry/80828
        set<int> nearlyPrimes = {6, 10, 14};

        if (n < 31)
            printf("NO\n");
        else
        {
            printf("YES\n");

            // Numbers should be distinct
            if ( (n==36) || (n==40) || (n==44) )
            {
                printf("6 10 15 %d\n", n - 30 - 1);
                
            }

            else{
                printf("6 10 14 %d\n", n - 30);
            }  
        }

    }

    return 0;
}

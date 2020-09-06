// B. Array Cancellation

#include <stdio.h>
#include <algorithm>

/*
// !!!!!!!!!!!!!!!!!!!!!!
// Time limit exceeded on test 9
// !!!!!!!!!!!!!!!!!!!!!!
int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        int a[n];
        for (int i=0; i<n; ++i){
            scanf("%d", &(a[i]));
        }
        scanf("\n");

        long long coins = 0;
        if (n==1)
        {
            if (a[0]==0) coins = 0;
            else coins = abs(a[0]);

        }
        else 
        {
            // for (auto it: a) printf("%d ", it);
            // printf("\n");

            // Zero cost operations
            for (int i=0; i<n; ++i)
            {
                if (a[i]<0) 
                {
                    continue;
                }
                else
                {
                    for (int j = i+1; j<n; ++j)
                    {
                        if (a[j]<0)
                        {
                            if (a[i] >= -a[j]) 
                            {
                                a[i] += a[j];
                                a[j] = 0;
                            }
                            else
                            {
                                a[j] = a[i] + a[j];
                                a[i] = 0;
                                break;
                            }
                            
                        }
                    }
                    
                } 
            }
            // for (auto it: a) printf("%d ", it);

            // 1 coin for each operation
            for (auto it: a) 
            {
                if (it > 0) coins+=it;
            }

        }

        printf("%lld\n", coins);
    }

    return 0;
}
*/
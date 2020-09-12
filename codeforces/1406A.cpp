// A. Subset Mex

#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;


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

        sort(a, a+n);

        int A;
        bool AFound = false;
        int B;
        bool BFound = false;

        int cnt = 0;
        int i=0;
        for (; i<n+1; ++i){
            cnt = count(a, a+n, i);
            if (cnt > 1) continue;
            else if (cnt == 1 && !BFound){
                B = i;
                BFound = true;
            }
            else if (cnt == 1 && !AFound){
                continue;
            }
            else if (cnt == 0){
                if (!BFound) {
                    B = i;
                    BFound = true;
                }
                if (!AFound){
                    A = i;
                    AFound = true;
                }
                break;
            }
        }

        cout << A + B  << endl;

    }

    return 0;
}
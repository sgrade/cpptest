// B. GCD Compression

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        vector<int> a(2*n);
        for (int i=0; i<2*n; ++i){
            scanf("%d\n", &(a[i]));
        }

        vector<bool> parity(2*n);
        for (int i=0; i<2*n; ++i){
            parity[i] = a[i]%2 == 0 ? false : true;
        }
        int odd = count(parity.begin(), parity.end(), true);

        int removeOdd;
        if (odd == 0) removeOdd = 0;
        else if (odd%2 != 0) removeOdd = 1;
        else removeOdd = 2;

        vector<bool> removed(2*n);
        for (int i=0; i<2*n && removeOdd>0; ++i){
            if (a[i]%2 != 0){
                removed[i] = true;
                --removeOdd;
            }
        }
        int removedCount = count(removed.begin(), removed.end(), true);

        for (int i=0; i<2*n - (2-removedCount); ++i){
            if (removed[i]) continue;

            for (int j=0; j<2*n; ++j){
                if (removed[j]) continue;
                
                else if (i != j){
                    if (a[i]%2 == a[j]%2){
                        printf("%d %d\n", i+1, j+1);
                        removed[i] = true;
                        removed[j] = true;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
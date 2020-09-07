// A. Points in Segments

#include <stdio.h>
#include <algorithm>


int main(){

    int n, m;
    scanf("%d %d\n", &n, &m);

    bool a[m+1];
    std::fill(a, a+m+1, false);

    for (int i=0; i<n; ++i){
        int l, r;
        scanf("%d %d\n", &l, &r);
        for (int j=l; j<r+1; j++){
            a[j] = true;
        }
    }

    int k = 0;
    for (int i=1; i<m+1; ++i){
        if (!a[i]) ++k;
    }
    printf("%d\n", k);

    for (int i=1; i<m+1; ++i){
        if (!a[i]) printf("%d ", i);
    }

    return 0;
}
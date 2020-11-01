// A. Nastya Is Reading a Book

#include <iostream>

int main(){

    int n, k, ans=0;
    scanf("%d\n", &n);

    int a[n], tmp;
    for (int i=0; i<n; ++i){
        scanf("%d %d\n", &tmp, &(a[i]));
    }

    scanf("%d\n", &k);

    for (int i=0; i<n; ++i){
        if (k <= a[i]){
            ans = n - i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}

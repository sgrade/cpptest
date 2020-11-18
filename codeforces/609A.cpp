// A. USB Flash Drives

#include <stdio.h>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    scanf("%d\n%d\n", &n, &m);
    
    int a[n];
    for (int i = 0; i < n; ++i){
        scanf("%d\n", &(a[i]));
    }
    sort(a, a+n, greater<int>());

    int ans = 0, tmp = 0;
    for (auto el: a){
        tmp += el;
        ++ans;
        if (tmp >= m) break;
    }

    printf("%d\n", ans);

    return 0;
}

// A. Game Shopping

#include <stdio.h>
#include <algorithm>


int main(){

    int n, m;
    scanf("%d %d\n", &n, &m);

    int c[n], a[m];
    for (auto &el: c) scanf("%d", &el);
    for (auto &el: a) scanf("%d", &el);

    int ans = 0;

    int i = 0;
    for (auto el: a){
        auto found = std::find_if(c+i, c+n, [el](int x){return x <= el;});
        if (found != c+n){
            i += std::distance(c+i, found) + 1;
            ++ans;
        }
        else break;
    }

    printf("%d\n", ans);

    return 0;
}

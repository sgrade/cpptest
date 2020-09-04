// A. Tanya and Stairways

#include <stdio.h>
#include <vector>


int main(){

    int n;
    scanf("%d\n", &n);

    int prev; 
    scanf("%d", &prev);

    if (n==1){
        printf("1\n1\n");
    }
    else{
        int t=1;
        std::vector<int> v;
        
        int cur = 0;
        for (int i=1; i<n; ++i){
            scanf("%d", &cur);
            if (cur == 1) {
                ++t;
                v.push_back(prev);
            }
            prev = cur;
            if (i==n-1){
                v.push_back(cur);
            }
        }
        printf("%d\n", t);
        for (auto it: v) printf("%d ", it);
    }

    return 0;
}
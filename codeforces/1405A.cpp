// A. Permutation Forgery

#include <stdio.h>
#include <vector>
#include <algorithm>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        std::vector<int> v;
        int tmp;
        for(int i=0; i<n; ++i){
            scanf("%d", &tmp);
            v.push_back(tmp);
        }

        std::vector<int> p;
        for (auto it=v.rbegin(); it!=v.rend(); ++it)
        {
            p.push_back(*it);
            printf("%d ", *it);
        }

        printf("\n");

    }

    return 0;
}
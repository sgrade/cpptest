// A. Puzzles

#include <stdio.h>
#include <algorithm>
#include <set>
#include <limits>       // numeric_limits


int main(){

    int n, m;
    scanf("%d %d\n", &n, &m);

    int a[m];
    for (int i=0; i<m; ++i){
        scanf("%d", &(a[i]));
    }

    std::sort(a, a+m);
    int output = std::numeric_limits<int>::max();
    for (int i=0; i<m-n+1; ++i){
        output = std::min(output, a[i+n-1] - a[i]);
    }
    
    
    // checking for duplicates
    std::set<int> st(a, a+m);
    if (st.size() < m){
        int maxNumOfDuplicates=0;
        for (auto it: st){
            int curNumOfDuplicates = std::count(a, a+m, it);
            if (curNumOfDuplicates > maxNumOfDuplicates){
                maxNumOfDuplicates = curNumOfDuplicates;
            }
        }
        if (maxNumOfDuplicates >= n) output = 0;
    }

    printf("%d\n", output);

    return 0;
}

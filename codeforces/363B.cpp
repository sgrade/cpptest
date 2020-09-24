// B. Fence

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main(){

    int n, k;
    scanf("%d %d\n", &n, &k);

    vector<int> h(n);
    for (int i=0; i<n; ++i){
        scanf("%d", &(h[i]));
    }

    // output
    // in the task indexing starts not from 0, but from 1
    int j = 1;
    
    int minSumOfHeights = accumulate(h.begin(), h.begin()+k, 0);
    int curSumOfHeights = minSumOfHeights;

    if (k<n){
        for (int i=k; i<n; ++i){
            curSumOfHeights += h[i] - h[i-k];
            if (curSumOfHeights < minSumOfHeights){
                minSumOfHeights = curSumOfHeights;
                // extra +1 is because in the task indexing starts not from 0, but from 1
                j = i-k+1 + 1;
            }
        }
    }

    cout << j << endl;

    return 0;
}
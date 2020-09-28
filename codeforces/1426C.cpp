// C. Increase and Copy

#include <stdio.h>
#include <algorithm>

int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        int n;
        scanf("%d\n", &n);

        // https://codeforces.com/blog/entry/83120
        int ans = 1e9;
        // We +1 until we reach x
        // Then we copy: add x times x (multiply x*x)
        // e.g. for 42:
        // First five moves: [1] -> [2] -> [3] -> [4] -> [5] -> [6]
        // Next six moves: -> [6,6] -> [6,6,6] -> [6,6,6,6] -> [6,6,6,6,6] -> [6,6,6,6,6,6] -> [6,6,6,6,6,6,6]
        // Total: eleven moves
		for (int x = 1; x * x <= n; ++x) {
            // x-1 is number of moves, when we do +1
            // 
			ans = std::min(ans, x - 1 + ((n - x) + x - 1) / x);
		}

        printf("%d\n", ans);

    }

    return 0;
}
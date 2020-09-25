// C - A x B + C

#include <stdio.h>

int main(){

    int N;
    scanf("%d\n", &N);

    // Editorial - https://atcoder.jp/contests/abc179/editorial/132
    int output = 0;
    for (int a=1; a<N; ++a){
        output += (N-1) / a;
    }

    printf("%d\n", output);

    return 0;
}
// A. Raising Bacteria

#include <stdio.h>


int main(){

    int x;
    scanf("%d\n", &x);

    // Editorial - https://codeforces.com/blog/entry/20368
    // Analysys:
    // Binary - decimal
    // 1        -   1
    // 10       -   2
    // 100      -   4
    // 1000     -   8
    // 10000    -   16
    // So, 1 means multiplied by 2
    // https://prog-cpp.ru/binary-arithmetics

    int bacteria = 0;
    while (x){

        // https://stackoverflow.com/questions/38922606/what-is-x-1-and-x-1
        // https://docs.microsoft.com/en-us/cpp/cpp/bitwise-and-operator-amp
        if (x&1) ++bacteria;
        x >>= 1;

    }

    printf("%d\n", bacteria);

    return 0;
}
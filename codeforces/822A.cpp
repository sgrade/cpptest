// A. I'm bored with life

#include <stdio.h>
#include <algorithm>


int factorial(int n)
{  
    if (n>1) return n * factorial(n-1);
    else return 1;
}

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if (a > b) std::swap(a, b);

    printf("%d\n", factorial(a));

    return 0;
}
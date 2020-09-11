// A. Game With Sticks

#include <iostream>


int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    int minimum = std::min(n, m);
    if (minimum%2 == 0){
        printf("Malvika\n");
    }
    else printf("Akshat\n");

    return 0;
}
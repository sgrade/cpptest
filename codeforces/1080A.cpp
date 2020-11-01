// A. Petya and Origami

#include <iostream>


int main(){

    int n, k;
    scanf("%d %d\n", &n, &k);

    int red = (n * 2 + k - 1) / k;
    int green = (n * 5 + k - 1) / k;
    int blue = (n * 8 + k - 1) / k;

    printf("%d\n", red + green + blue);

    return 0;
}

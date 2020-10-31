// A. Compote

#include <iostream>
#include <algorithm>

int main(){

    int a, b, c;
    scanf("%d\n%d\n%d\n", &a, &b, &c);

    std::cout << std::min({a, b/2, c/4}) * 7 << std::endl;
    
    return 0;
}

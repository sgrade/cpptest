// A. Playing with Dice

#include <iostream>


int main(){

    int a, b;
    scanf("%d %d\n", &a, &b);

    int first = 0, draw = 0, second = 0;

    for (int i=1; i<7; ++i){
        if (abs(a-i) < abs(b-i)) ++first;
        else if (abs(b-i) < abs(a-i)) ++second;
        else ++draw;
    }

    std::cout << first << ' ' << draw << ' ' << second << std::endl;

    return 0;
}

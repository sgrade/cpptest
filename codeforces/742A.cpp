// A. Arpa’s hard exam and Mehrdad’s naive cheat

#include <iostream>


int main(){

    long long n;
    std::cin >> n;

    // 8^0 = 1
    int output = 1;

    // Editorial - https://codeforces.com/blog/entry/48871
    // 8^2=   64:     8*8 = 64, where last digit is 4
    // 8^3=  512:     4*8 = 32, where last digit is 2
    // 8^4= 4096:     2*8 = 16, where last digit is 6
    // 8^5=32768:     6*8 = 48, where last digit is 8
    // 8^6:           8*8 - we had before - cycle repeats
    // The cycle includes 4 options, so we need to find n%4
    // n%4 = 2, the last digit is 4
    // n%4 = 3, the last digit is 2
    // n%4 = 0, the last digit is 6
    // n%4 = 1, the last digit is 8

    if (n>0){
        switch (n%4)
        {
        case 2:
            output = 4;
            break;
        case 3:
            output = 2;
            break;
        case 0:
            output = 6;
            break;
        case 1:
            output = 8;
            break;
        default:
            break;
        }
    }

    std::cout << output << std::endl;

    return 0;
}
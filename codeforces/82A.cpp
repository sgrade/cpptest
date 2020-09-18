// A. Double Cola

#include <iostream>
#include <math.h>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string a[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    long long index = 0;
    if (n<=5){
        index = n-1;
    }
    else {
        long long tmp = 0;
        int p=0;
        while (true){
            tmp += 5*pow(2, p);
            if (tmp > n) break;
            else ++p;
        }

        index = n - (tmp - 5*pow(2, p));
        index /= pow(2, p);
    }

    cout << a[index] << endl;

    return 0;
}
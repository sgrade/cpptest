// A. Expression

#include <iostream>

using namespace std;


int main(){

    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    int output = 0;
    for (int i=0; i<3; ++i){
        
        if (a[i] == 1) {
            if (i==0 || i==1) output = (a[0]+a[1])*a[2];
            if (i==1 || i==2) output = max(output, a[0]*(a[1]+a[2]));
            output = max(output, a[0]+a[1]+a[2]);
        }

    }

    output = max(output, a[0]*a[1]*a[2]);

    cout << output << endl;

    return 0;
}
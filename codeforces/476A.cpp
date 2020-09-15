// A. Dreamoon and Stairs

#include <iostream>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int moves = 0;
    
    // min moves = n/2
    // max moves = n/1

    if (n<m){
        moves = -1;
    }
    else {
        if (n%2==0 && (n/2)%m==0){
            moves = n/2;
        }
        else{
            moves = n/2;
            if (n%2!=0) ++moves;
            while((moves%m)!=0 && moves<=n){
                ++moves;
            }
        }
    }

    cout << moves << endl;

    return 0;
}
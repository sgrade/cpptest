// A. Brain's Photos

#include <iostream>

using namespace std;


int main(){

    int n, m;
    scanf ("%d %d\n", &n, &m);

    for (int i=0; i<n; ++i){
        char ch;
        for (int j=0; j<m; ++j){
            cin >> ch;
            if (ch == 'C' || ch == 'M' || ch == 'Y') {
                cout << "#Color";
                exit(0);
            }
        }
    }

    cout << "#Black&White";

    return 0;
}
// 

#include <iostream>

using namespace std;

bool isP (int x){
    if (x == 0 || x == 1){
        return false;
    }
    else {
        for (int i=2; i<x; ++i){
            if (x%i == 0){
                return false;
            }
        }
    }
    return true;
}

void printCluster(int n, int filler){
    for (int i=0; i<n; ++i){
        for (int j=0; j<n; ++j){
            cout << filler << ' ';
        }
        cout << endl;
    }
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        if (isP(n)){
            printCluster(n, 1);
        }
        else {
            int clusterSize = 0;
            for (int i = 2; i<n; ++i){
                if (n % i == 0) {
                    clusterSize = i;
                    break;
                }
            }
            int clusters = n / clusterSize;

            int clusterStart = 0;
            int clusterEnd = clusterStart + clusterSize;

            for (int i=0; i<n; ++i){
                if (i > 1 && i % clusterSize == 0){
                    clusterStart += clusterSize;
                    clusterEnd += clusterSize;
                }
                for (int j=0; j<n; ++j){
                    if (j >= clusterStart && j <clusterEnd){
                        cout << 1 << ' ';
                    }
                    else {
                        cout << 0 << ' ';
                    }
                }
                cout << endl;
            }
        }
    }

    return 0;
}

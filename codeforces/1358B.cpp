// B. Maria Breaks the Self-isolation

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int a[n];
        for (int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort (a, a+n);

        int grannies = 1;
        for (int i=0; i<n; ++i){
            if (a[i] <= grannies){
                ++grannies;
            }
            else if (i!=n-1){
                int tmpGrannies = grannies;
                for (int j=i+1; j<n; ++j){
                    ++tmpGrannies;
                    if (a[j] <= tmpGrannies){
                        grannies = tmpGrannies+1;
                        i = j;
                        break;
                    }
                    else if(a[j] > n) break;
                }
            }
        }

        cout << grannies << endl;

    }

    return 0;
}
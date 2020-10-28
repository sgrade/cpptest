// A. Make a triangle!

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int arr[3];
    for (int i=0; i<3; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+3);
    
    int ans = 0;
    if (arr[0]+arr[1] <= arr[2]){
    
        int a = arr[0];
        int b = arr[1];
    
        while(a+b <= arr[2]){
            if (a < b) ++a;
            else ++b;
        }

        ans = a - arr[0];
        ans += b - arr[1];

    }

    
    cout << ans << endl;

    return 0;
}

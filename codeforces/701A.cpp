// A. Cards

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];

    int sum = 0;
    for (int i=0; i<n; ++i){
        cin >> a[i];
        sum += a[i];
    }

    int av = sum / (n/2);

    bool visited[n] = {0};
    int count = 0;
    for (int i=0; i<n && count<n/2; ++i){
        if (visited[i]) continue;

        visited[i] = true;

        int j=0;
        for (; j<n; ++j){
            if (!visited[j] && a[j] == av-a[i]){
                visited[j] = true;
                break;
            }
        }
        
        cout << i+1 << ' ' << j+1 << endl;
        
        ++count;
    }

    return 0;
}
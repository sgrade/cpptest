// A. Almost Prime

#include <iostream>
#include <math.h>
#include <set>

using namespace std;


set<int> allDistinctPrimeFactors(int n){
    // based on relevant template
    set<int> a;
    if(n == 0 || n == 1){
        return a;
    }

    while(n % 2 == 0) {
        a.insert(2);
        n /= 2;
    }

    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            a.insert(i);
            n /= i;
        }
    }

    if(n > 2) a.insert(n);

    return a;

}


int main(){

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; ++i){
        if (allDistinctPrimeFactors(i).size() == 2) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}

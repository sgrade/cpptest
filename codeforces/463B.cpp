// B. Caisa and Pylons

#include <stdio.h>
#include <algorithm>

using namespace std;


int main(){

    int n;
    scanf("%d\n", &n);

    int dollars = 0;

    // Initially Caisa stand at 0 pylon and has 0 energy.
    int prev = 0;
    int energy = 0;

    int cur;

    for (int i=0; i<n; ++i){
        scanf("%d", &cur);

        // Editorial - https://codeforces.com/blog/entry/13631
        energy += prev - cur;
        if (energy < 0){
            dollars += - energy;
            energy = 0;
        }
        
        prev = cur;
    }

    printf("%d\n", dollars);

    return 0;
}
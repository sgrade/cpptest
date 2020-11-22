// A. Nicholas and Permutation

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a) cin >> el;

    int ma = distance(a, max_element(a, a+n));
    int mi = distance(a, min_element(a, a+n));

    int current_distance = max(ma, mi) - min(ma, mi);
    int candidate_right = (n-1) - max(ma, mi);
    int candidate_left = min(ma, mi);
    if (candidate_right > candidate_left){
        cout << n - 1 - min(ma, mi) << endl;
    }
    else {
        cout << max(ma, mi) << endl;
    }

    return 0;
}

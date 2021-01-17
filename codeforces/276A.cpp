// A. Lunch Rush

#include <iostream>
#include <limits>
#include <algorithm>


int main(){

    int n, k;
    std::cin >> n >> k;

    int max_joy = std::numeric_limits<int>::min();
    for (int i = 0; i < n; ++i){
        int f, t;
        std::cin >> f >> t;
        
        int current_joy = t <= k ? f : f - (t - k);
        max_joy = std::max(max_joy, current_joy);
    }

    std::cout << max_joy << std::endl;

    return 0;
}

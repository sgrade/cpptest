// A. Elevator or Stairs?

#include <iostream>
#include <algorithm>


int main(){

    int x, y, z, t1, t2, t3;
    std::cin >> x >> y >> z >> t1 >> t2 >> t3;

    int floors = abs(x - y);
    int timeStairs = floors * t1;
    int timeElevator = abs(x - z) * t2 + floors * t2 + 3 * t3;

    std::cout << (timeElevator <= timeStairs ? "YES\n" : "NO\n");

    return 0;
}

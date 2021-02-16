// A. Cheap Travel

#include <iostream>
#include <algorithm>


int main() {

    int n, m, a, b;
    std::cin >> n >> m >> a >> b;

    int sum1 = n * a;

    int sum2 = n / m * b;
    sum2 += std::min((n % m) * a, b);

    std::cout << std::min(sum1, sum2) << std::endl;

    return 0;
}

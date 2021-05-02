// B. Phoenix and Puzzle

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
using ull = unsigned long long;

int main() {

    int t;
    cin >> t;

    set<ull> dp;

    ull triangles = 2;
    while (triangles < 1000000000) {
        dp.insert(triangles);
        triangles *= 4;
    }

    triangles = 4;
    while (triangles < 1000000000) {
        dp.insert(triangles);
        triangles *= 4;
    }

    triangles = 2;
    ull sum = triangles;
    ull layers = 1;
    while (sum <= 1000000000) {
        ++layers;
        sum += triangles * layers  + triangles * (layers - 1);
        dp.insert(sum); 
    }


    triangles = 4;
    sum = triangles;
    layers = 1;
    while (sum <= 1000000000) {
        ++layers;
        sum += triangles * layers  + triangles * (layers - 1);
        dp.insert(sum); 
    }

    while (t--) {

        int n;
        cin >> n;

        bool ans = false;

        if (dp.find(n) != dp.end()) {
            ans = true;
        }
        
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}

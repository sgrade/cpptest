// A. Nastya and Rice

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        float totalMax = c+d;
        float totalMin = c-d;

        int singleMax = a+b;
        int singleMin = a-b;

        float targetMax = totalMax / n;
        float targetMin = totalMin / n;

        if (singleMax < targetMin || singleMin > targetMax) cout << "NO\n";
        else cout << "YES\n";

    }

    return 0;
}
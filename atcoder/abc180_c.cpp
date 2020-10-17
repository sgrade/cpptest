// C - Cream puff

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


int main(){

    unsigned long long n;
    cin >> n;

    vector<unsigned long long> v;

    unsigned long long tmp;
    unsigned long long count = 0;
    for (int i=1; i<=sqrt(n); ++i){
        if (n%i == 0){
            tmp = n/i;
            v.push_back(tmp);
            cout << i << endl;
        }
    }

    if (v.back() == sqrt(n)) v.erase(v.end()-1);

    for (int i = v.size()-1; i>=0; --i){
        cout << v[i] << endl;
    }

    return 0;
}

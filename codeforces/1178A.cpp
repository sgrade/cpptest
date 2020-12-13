// A. Prime Minister

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a) cin >> el;

    int half = accumulate(a, a+n, 0) / 2;

    int k = 0;
    vector<int> ans = {1};
    int sumAns = a[0];

    if (sumAns > half){
        k = 1;
    }
    else{
        for (int i = 1; i < n; ++i){
            if (a[i] > a[0] / 2) continue;
            
            // else
            ans.push_back(i + 1);
            sumAns += a[i];
            if (sumAns > half){
                k = ans.size();
                break;
            }
        }
    }

    cout << k << endl;
    if (k > 0){
        for (auto el: ans) cout << el << ' ';
        cout << endl;
    }

    return 0;
}

// B. Mahmoud and a Triangle

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> a;
    map<int, int> mp;
    int tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        ++mp[tmp];
        if (mp[tmp] < 4){
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end(), greater<int>());

    bool ans = false;

    bool stop = false;
    for (int i=0; i<a.size(); ++i){
        if (stop) break;
        for (int j=0; j<a.size(); ++j){
            if (stop) break;
            for (int k=0; k<a.size(); ++k){
                if (i == j || i == k || j == k) continue;
                else {
                    if (a[i] < a[j] + a[k]){
                        if (a[j] < a[i] + a[k]){
                            if (a[k] < a[i] + a[j]){
                                stop = true;
                                ans = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}

// B. Preparing Olympiad

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


vector<int> people;
vector<int> combination;

int l, r, x, ans = 0;

void check_combination(vector<int> v)
{   
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum >= l && sum <= r)
    {
        auto mn_mx = minmax_element(combination.begin(), combination.end());
        if (*mn_mx.second - *mn_mx.first >= x)
        {
            ++ans;
        }
    }
}

// https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c/28698654
void go(int offset, int k) {
    if (k == 0) {
    check_combination(combination);
    return;
    }
    for (int i = offset; i <= people.size() - k; ++i) {
        combination.push_back(people[i]);
        go(i+1, k-1);
        combination.pop_back();
    }
}


int main(){

    int n;
    cin >> n >> l >> r >> x;

    vector<int> c(n);
    for (auto &el: c)
    {
        cin >> el;
    }

    for (int i = 2; i < c.size()+1; ++i)
    {
        people.clear();
        for (auto el: c)
            people.push_back(el);
        
        go(0, i);
        
    }

    cout << ans << endl;

    return 0;
}

// B. Preparing Olympiad
// Wrong answer on test 4

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <numeric>

using namespace std;


vector<int> people;
vector<int> combination;

int l, r, x, ans = 0;
map<int, int> mp;

void check_combination(vector<int> v)
{
    int current_ans;
    
    int sum = accumulate(v.begin(), v.end(), 0);
    if (sum >= l && sum <= r)
    {
        bool flag = true;
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i] - v[i-1] < x)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            current_ans = 1;
            for (auto &el: combination)
                current_ans *= mp[el];
            ans += current_ans;
        }
    }
}


// https://stackoverflow.com/questions/12991758/creating-all-possible-k-combinations-of-n-items-in-c/28698654
/*
void pretty_print(const vector<int>& v) {
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << "] " << endl;
}
*/

void go(int offset, int k) {
    if (k == 0) {
    // pretty_print(combination);
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
    // int l, r, x;
    cin >> n >> l >> r >> x;

    set<int> c;
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        c.insert(tmp);
        ++mp[tmp];
    }

    // int ans = 0;

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

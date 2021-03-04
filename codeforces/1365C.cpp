// C. Rotation Matching
// NOT finished

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    deque<int> a(n), b(n);
    for (auto &el: a)
        cin >> el;
    for (auto &el: b)
        cin >> el;
    
    int ans = 0;

    int current_ans;
    for (int i = 0; i < n; ++i)
    {
        b.push_front(b.back());
        b.pop_back();
        
        current_ans = 0;
        for (int j = 0; j < n; ++j)
        {
            if (a[j] == b[j]) 
                ++current_ans;
        }
        ans = max(ans, current_ans);
    }

    cout << ans << endl;

    return 0;
}

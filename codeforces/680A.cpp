// A. Bear and Five Cards

#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int t[5];
    set<int> st;
    for (auto &el: t) {
        cin >> el;
        st.insert(el);
    }

    int sum = accumulate(t, t+5, 0);
    int ans = sum;

    for (auto x: st){
        int cnt = count(t, t+5, x);
        if (cnt > 1){
            int candidateAnswer = sum - x * min(3, cnt);
            if (candidateAnswer < ans) ans = candidateAnswer;
        }
    }

    cout << ans << endl;

    return 0;
}

// B. Max and Mex

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int tmp;
        set<int> st;

        for (int i = 0; i < n; ++i)
        {
            cin >> tmp;
            st.insert(tmp);
        }

        int ans = st.size();
        
        if (k > 0)
        {
            int a = 0, b = *st.rbegin();
            while(st.find(a) != st.end())
                ++a;
            
            b = *st.rbegin();
            
            tmp = (a + b + 1) / 2;

            // Idea from - https://codeforces.com/contest/1496/submission/109640110
            // Explanation in - https://www.youtube.com/watch?v=g8bYHwPjhLM
            // a (MEX) is always the same, so b will be the same as well - no need to do anything
            if (tmp != a)
            {
                st.insert(tmp);
                k = 0;
            }
            
            ans = st.size() + k;
        }

        cout << ans << endl;
    }
}

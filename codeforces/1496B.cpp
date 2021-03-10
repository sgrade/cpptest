// B. Max and Mex
// Memory limit exceeded on pretest 2

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

        int ans = 1;
        
        if (st.size() > 1)
        {
            set<int>::iterator it = st.begin();
            int a = 0, b;

            for (int i = 0; i < k; ++i)
            {
                while (a == *it)
                {
                    ++a;
                    ++it;
                }
                if (a > *it)
                {
                    if (it != st.end())
                    {
                        ++it;
                    }
                }

                b = *st.end();
                tmp = (a + b + 2 - 1) / 2;

                st.insert(tmp);
            }
        }

        cout << st.size() << endl;
    }
}

// A. Meximization

#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--)
    {
        int n; 
        cin >> n;

        vector<int> v;
        set<int> st;
        int tmp;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            if (st.find(tmp) == st.end())
            {
                st.insert(tmp);
            }
            else
            {
                v.push_back(tmp);
            }
        }
        
        for (auto el: st)
        {
            cout << el << ' ';
        }
        for (auto el: v)
        {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}

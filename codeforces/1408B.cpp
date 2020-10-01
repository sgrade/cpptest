// B. Arrays Sum

#include <iostream>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, k;
        cin >> n >> k;

        set<int> st;

        int tmp;
        for (int i=0; i<n; ++i){
            cin >> tmp;
            st.insert(tmp);
        }

        int ans;
        int c = st.size();

        // Editorial - https://codeforces.com/blog/entry/83233
        // Errichto's - https://www.youtube.com/watch?v=-L7ZmRjlHmI

        if (k==1) {
            if (c>1) ans = -1;
            else ans = 1;
        }

        /* 
        Test: #9
        1
        4 4
        1 1 1 1
        */
        else if (k >= c){
            ans = 1;
        }

        else {
            --c;
            // https://stackoverflow.com/questions/17944/how-to-round-up-the-result-of-integer-division
            ans = (c + (k-1)-1) / (k-1);
        }

        cout << ans << endl;

    }

    return 0;
}
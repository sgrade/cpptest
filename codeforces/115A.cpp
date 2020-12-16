// A. Party

#include <iostream>
#include <set>

using namespace std;


int main(){

    int t;
    cin >> t;

    set<int> st;
    
    int tmp;
    while(t--){
        cin >> tmp;
        st.insert(tmp);
    }

    cout << st.size() << endl;

    return 0;
}

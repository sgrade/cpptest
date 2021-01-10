// A. DZY Loves Hash

#include <iostream>
#include <set>


int main(){

    int p, n;
    std::cin >> p >> n;

    int ans = -1;

    std::set<int> st;
    int x;
    for(int i = 1; i < n+1; ++i){
        std::cin >> x;
        int h = x % p;
        if(st.find(h) != st.end()) {
            ans = i;
            break;
        }
        else {
            st.insert(h);
        }
    }

    std::cout << ans << std::endl;

    return 0;
}

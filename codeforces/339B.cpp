// B. Xenia and Ringroad

#include <iostream>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    long long output=0;
    int rings = 0;
    int last;
    int cur;
    cin >> last;

    if (m>1) {
        
        for (int i=1; i<m; ++i){
            cin >> cur;
            if (cur < last){
                ++rings;
            }
            last = cur;
        }
    }
    
    output = (long long)rings*n + max(0, cur-1);
    cout << output << endl;

    return 0;
}
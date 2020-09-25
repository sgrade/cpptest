// B - Interactive Sorting
// Works only for the first test case - for 100 points
// 

// Adopted solution of atcoder.jp
// This contest is for practice:
// it is not required to solve it, only check how the interface works

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(void){
    int N,Q;
    
    cin >> N >> Q;
    
    string s;
    for(int i=0; i<N; i++){
        s += (char)('A' + i);
    }
    
    for (int i=0; i<N; ++i){
        for (int j=0; j<N-1; j++){
            cout << "? " << s[j] << ' ' << s[j+1] << endl << flush;
            char ans;
            cin >> ws >> ans;
            if(ans == '>') swap(s[j], s[j+1]);
        }
    }
    
    cout << "! " << s << endl << flush;
    
    return 0;
}
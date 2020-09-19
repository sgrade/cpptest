// A. Digit Game

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        vector<int> v;

        string s;
        getline(cin >> ws, s);

        int tmp;
        for (int i=0; i<n; ++i){
            tmp = (int)s[i] - 48;
            v.push_back(tmp);
        }

        int output;
        int r=0;
        int b=0;
        for (int i=0; i<n-1; ++i){
            bool moveUsed = false;
            // Raze chooses
            if (i%2 == 0){
                for (; r<n; ++r){
                    if (v[r] == -1) continue;
                    else if (r%2==0 && v[r]%2==0){
                        v[r] = -1;
                        moveUsed = true;
                        break;
                    }
                }
                if (!moveUsed && r==n){
                    for (int j=0; j<n; ++j){
                        if (j%2 == 0){
                            v[j] = -1;
                            break;
                        }
                    }
                }
            }
            // B chooses
            else {
                for (; b<n; ++b){
                    if (v[b] == -1) continue;
                    else if (b%2!=0 && v[b]%2!=0){
                        v[b] = -1;
                        moveUsed = true;
                        break;
                    }
                }
                if (!moveUsed && b==n){
                    for (int j=0; j<n; ++j){
                        if (j%2 != 0){
                            v[j] = -1;
                            break;
                        }
                    }
                }
            }

        }

        for (int i=0; i<n; ++i){
            if (v[i]!=-1){
                if (v[i]%2==0) output = 2;
                else output = 1;
            }
            
        }
 
        cout << output << endl;

    }

    return 0;
}
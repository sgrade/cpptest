// A. Case of the Zeros and Ones

#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    // Editorial - https://codeforces.com/blog/entry/18919
    string s;
    getline(cin >> ws, s);

    int numOfZeroes = 0;
    int numOfOnes = 0;
    for (int i=0; i<n; ++i){
        if (s[i] == '0') ++numOfZeroes;
        else ++numOfOnes;
    }

    cout << abs(numOfZeroes - numOfOnes) << endl;

    /*
    // Time limit exceeded on test 12
    int output = 0;

    
    if (s.size()==1){
        output = 1;
    }
    else {
                
        bool continueSearch = true;
        while(continueSearch){
            string::size_type index;
            index = s.find("10");
                if (index == string::npos){
                    index = s.find("01");
                }
            if (index == string::npos){
                continueSearch = false;
            }
            else{
                s.erase(index, 2);
            }
        }
        
    }
    cout << s.size() << endl;
    */


    return 0;
}
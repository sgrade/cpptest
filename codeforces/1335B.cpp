// B. Construct the String

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, a, b;
        cin >> n >> a >> b;

        // Alphabet
        char al[26];
        int i = 0;
        for (int c = 97; c <= 122; c++) {
		    al[i] = char(c);
            ++i;
	    }

       int aCount = 0;
       int bCount = 0;
       char output[n];
       for (int i=0; i<n; ++i){
            if (aCount == a) {
                aCount = 0;
                bCount = 0;
            }
            if (bCount == b) bCount = 0;

            output[i] = al[bCount];
            ++aCount;
            ++bCount;
        }

        for (auto it: output) cout << it;
        cout << endl;

    }

    return 0;
}
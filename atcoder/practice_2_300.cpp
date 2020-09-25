// B - Interactive Sorting
// NOT FINISHED !!!
// Tried to experiment with merge sort, but haven't finished

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool checkInput(char ai, char aj){
    // https://support.microsoft.com/en-us/help/94227/how-to-flush-the-cout-buffer-in-visual-c
    // cout.flush();
    // cout << ... << flush;
    cout << '?' << ai << aj << endl << flush;
    char ans;
    cin >> ans;
    return ans=='<' ? true : false;
}

// https://en.wikipedia.org/wiki/Merge_sort#Bottom-up_implementation
void bottomUpMerge(vector<char> &A, int iLeft, int iRight, int iEnd, vector<char> &B){
    int i = iLeft, j=iRight;
    for (int k=iLeft; k<iEnd; ++k){
        
        // This original code from Wikipedia
        // if (i < iRight && (j >= iEnd || A[i] <= A[j])){

        // Replaced with what is required in the problem       
        if (i < iRight){
            if (j >= iEnd){
                B[k] = A[i];
                ++i;
                continue;
            }
            // Only ask when need to compare two chars
            else if (checkInput(A[i], A[j])){
                B[k] = A[i];
                ++i;
            }
        }
        else {
            B[k] = A[j];
            ++j;
        }
    }
}

void copyArray(vector<char> &B, vector<char> &A, int n){
    for (int i=0; i<n; ++i){
        A[i] = B[i];
    }
}

// array A[] has the items to sort; array B[] is a work array
void bottomUpMergeSort(vector<char> &A, vector<char> &B, int n){
    for (int w=1; w < n; w *= 2){
        for (int i = 0; i < n; i = i + 2 * w){
            bottomUpMerge (A, i, min(i+w, n), min(i+2*w, n), B);           
        }
        copyArray(B, A, n);
    }
}


int main(){

    int N, Q, c1, c2;

    cin >> N >> Q;

    // Alphabet
    vector<char> v(N);
    //for (int c = 65; c < 65+N; ++c) {
    for (int c = 0; c < N; ++c) {
		v[c]=char(c+65);
	}

    vector<char> b(N);
    bottomUpMergeSort(v, b, N);

    
    string output = "!";
    for (auto it: v){
        output += it;
    }
    // cout << endl << flush;
    exit(0);
    
    return 0;
}
// B. Lecture

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> a;
    unordered_map<string, int> b;
    unordered_map<int, string> shortest;

    string tmpA, tmpB;
    for (int i=0; i<m; ++i){
        cin >> tmpA >> tmpB;
        a[tmpA] = i;
        b[tmpB] = i;
        shortest[i] = tmpB.size() < tmpA.size() ? tmpB : tmpA;
    }

    string word;
    int index;
    for (int i=0; i<n; ++i){
        cin >> word;
        index = a.find(word)!=a.end() ? a[word] : b[word];
        cout << shortest[index] << ' ';
    }

    cout << endl;

    return 0;
}
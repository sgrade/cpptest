// B. Sereja and Suffixes
 
#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
 
using namespace std;
 
 
int main(){
 
    int n, m;
    scanf("%d %d\n", &n, &m);
 
    vector<int> a(n);
    int tmp;
    for (int i=0; i<n; ++i){
        scanf("%d", &tmp);
        a[i]=tmp;
    }
    scanf("\n");
 
    set<int> distinct;
    vector<int> distinctCount(n);
    for (int i=n-1; i>=0; i--){
        distinct.insert(a[i]);
        distinctCount[i] = distinct.size();
    }
 
    for (int i=0; i<m; ++i){
        scanf("%d\n", &tmp);
        cout << distinctCount[tmp-1] << endl;
    }
 
    return 0;
}
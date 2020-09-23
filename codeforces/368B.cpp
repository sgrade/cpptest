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
 
    vector<int> a;
    int tmp;
    for (int i=0; i<n; ++i){
        scanf("%d\n", &tmp);
        a.push_back(tmp);
    }
 
    set<int> distinct;
    deque<int> distinctCount;
    int uniq = 0;
    for (int i=m-1; i>=0; i--){
        auto it = find(distinct.begin(), distinct.end(), a[i]);
        if ( it == distinct.end()){
            ++uniq;
        }
        distinctCount.push_front(uniq);
        distinct.insert(a[i]);
    }
 
    for (int i=0; i<m; ++i){
        scanf("%d\n", &tmp);
        cout << distinctCount[tmp-1] << endl;
    }
 
    return 0;
}
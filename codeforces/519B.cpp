// B. A and B and Compilation Errors

#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int n;
    scanf("%d\n", &n);

    vector<int> a, b, c;

    int tmp;
    for (int i=0; i<n; ++i){
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    scanf("\n");
    sort(a.begin(), a.end());

    for (int i=0; i<n-1; ++i){
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    scanf("\n");
    sort(b.begin(), b.end());

    for (int i=0; i<n-2; ++i){
        scanf("%d", &tmp);
        c.push_back(tmp);
    }
    sort(c.begin(), c.end());

    vector<int> errors;

    set_difference(a.begin(), a.end(), b.begin(), b.end(), 
                    inserter(errors, errors.begin()));
                    
    set_difference(b.begin(), b.end(), c.begin(), c.end(), 
                    inserter(errors, errors.begin()+1));

    for (auto it: errors){
        printf("%d\n", it);
    }

    return 0;
}
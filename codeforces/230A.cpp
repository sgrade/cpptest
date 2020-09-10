// A. Dragons

#include <stdio.h>
#include <map>


int main(){

    int s, n;
    scanf("%d %d\n", &s, &n);

    bool defeat = false;
    std::multimap<int, int> m;
    for (int i=0; i<n; ++i){
        int x, y;
        scanf ("%d %d\n", &x, &y);
        m.insert(std::pair<int, int>(x, y));
    }

    for (auto it: m) {
        if (s>it.first) s+=it.second;
        else {
            defeat = true;
            break;
        }
    }

    printf("%s\n", (defeat ? "NO" : "YES"));

    return 0;
}

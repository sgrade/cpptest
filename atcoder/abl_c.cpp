// C - Connect Cities
// NOT FINISHED:
// need to implement connected graph, BFS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    vector<bool> nodes(n, 0);

    for (int i=0; i<m; ++i){
        int a1, b1;
        cin >> a1 >> b1;

        nodes[a1-1] = true;
        nodes[b1-1] = true;
    }

    cout << count(nodes.begin(), nodes.end(), 0) << endl;

    return 0;
}
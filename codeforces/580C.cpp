// C. Kefa and Park

#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> a = {0};
int ans = 0, current_ans;


// A class to represent a graph object
class Graph
{
    // Number of vertices
    int V;
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);

    public:
        Graph(int V);
        vector<vector<int>> adjList;
        void addEdge(int x, int y);
        // DFS traversal of the vertices reachable from v
        void DFS(int v);
};

Graph::Graph(int N)
{
    this -> V = N;
    // resize the vector to hold "N" elements of type "vector<int>"
    adjList.resize(N); 
}

void Graph::addEdge(int x, int y)
{
    adjList[x].push_back(y);
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;
    
    // Print it
    cout << a[0] << " ";
 
    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator it;
    for (it = adjList[v].begin(); it != adjList[v].end(); ++it)
        if (!visited[*it])
            DFSUtil(*it, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // 580C-specific
    current_ans = 0;
    
    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}


// Driver code


int main()
{
	int n, m;
    cin >> n >> m;

    int tmp;
    for (int i = 1; i < n + 1; ++i) 
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    
    // Create a graph given in the above diagram
	// +1 is for 1-based indexes
    Graph g(n + 1);
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }

	// DFS starting from vertex X
	g.DFS(1);
    cout << endl;

	return 0;
}

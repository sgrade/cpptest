// C. Kefa and Park

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int m;
vector<int> a = {0}, consequitive_cats = {0};
int ans = 0, current_ans;


// A class to represent a graph object
class Graph
{
    // Number of vertices
    int V;
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[], int parent);

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
    adjList[y].push_back(x);
}

void Graph::DFSUtil(int v, bool visited[], int parent)
{
    // Mark the current node as visited
    visited[v] = true;
    
    if (a[v])
        consequitive_cats[v] = consequitive_cats[parent] + 1;
    
    if (consequitive_cats[v] <= m)
    {
        if (adjList[v].size() == 1 && visited[adjList[v][0]])
        {
                ++ans;
        }
        else
        {
            for (auto el: adjList[v])
            {
                if (!visited[el]){
                    DFSUtil(el, visited, v);
                }
            }
        }
    }
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
   
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited, 0);
}


int main()
{
	int n;
    cin >> n >> m;

    consequitive_cats.resize(n + 1, 0);

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
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x >> y;
        g.addEdge(x, y);
    }

	// DFS starting from vertex X
	g.DFS(1);
    cout << ans << endl;

	return 0;
}

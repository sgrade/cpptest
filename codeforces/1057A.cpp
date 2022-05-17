// A. Bmail Computer Network

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


size_t n;
vector<size_t> ans;


// graph implementation is from 
// https://github.com/TheAlgorithms/C-Plus-Plus/blob/master/graph/depth_first_search.cpp
namespace graph {
/**
 * \brief
 * Adds and edge between two vertices of graph say u and v in this
 * case.
 *
 * @param adj Adjacency list representation of graph
 * @param u first vertex
 * @param v second vertex
 *
 */
void addEdge(std::vector<std::vector<size_t>> *adj, size_t u, size_t v) {
    /*
     *
     * Here we are considering undirected graph that's the
     * reason we are adding v to the adjacency list representation of u
     * and also adding u to the adjacency list representation of v
     *
     */
    (*adj)[u - 1].push_back(v - 1);
    (*adj)[v - 1].push_back(u - 1);
}

/**
 *
 * \brief
 * Explores the given vertex, exploring a vertex means traversing
 * over all the vertices which are connected to the vertex that is
 * currently being explored.
 *
 * @param adj garph
 * @param v vertex to be explored
 * @param visited already visited vertices
 *
 */
void explore(const std::vector<std::vector<size_t>> &adj, size_t v,
             std::vector<bool> *visited) {
    // std::cout << v + 1 << " ";
    (*visited)[v] = true;
    ans.push_back(v + 1);
    
    if (v + 1 == n) {
        for (size_t &el: ans) {
            cout << el << ' ';
        }
        cout << '\n';
        return;
    }
    for (auto x : adj[v]) {
        if (!(*visited)[x]) {
            explore(adj, x, visited);
        }
    }
    ans.pop_back();
}

/**
 * \brief
 * initiates depth first search algorithm.
 *
 * @param adj adjacency list of graph
 * @param start vertex from where DFS starts traversing.
 *
 */
void depth_first_search(const std::vector<std::vector<size_t>> &adj,
                        size_t start) {
    size_t vertices = adj.size();

    std::vector<bool> visited(vertices, false);
    explore(adj, start, &visited);
}
}  // namespace graph


int main() {

    cin >> n;

    // creating graph
    vector<vector<size_t>> adj(n + 1, vector<size_t>());
    
    // taking input for edges
    size_t u;
    for (int i = 2; i < n + 2; ++i) {
        cin >> u;
        graph::addEdge(&adj, i, u);
    }

    ans.clear();

    // running depth first search over graph
    graph::depth_first_search(adj, 0);

    return 0;
}

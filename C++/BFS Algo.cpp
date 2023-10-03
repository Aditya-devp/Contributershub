// Breadth-first search (BFS) is an algorithm to traverse or search in data structures like a tree or a graph.

// As we mentioned, we can use BFS to do level-order traversal in a tree.

// We can also use BFS to traverse a graph. For example, we can use BFS to find a path, especially the shortest path, from a start node to a target node.

// We can use BFS, in even more abstract scenarios, to traverse all the possible statuses. In this case, we can regard the statuses as the nodes in the graph while the legal transition paths as the edges in the graph.

// Code:
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {0, 3, 4},  // Node 1 is connected to nodes 0, 3, and 4
        {0, 5},     // Node 2 is connected to nodes 0 and 5
        {1},        // Node 3 is connected to node 1
        {1},        // Node 4 is connected to node 1
        {2}         // Node 5 is connected to node 2
    };

    cout << "Breadth-First Traversal starting from node 0:" << endl;
    bfs(graph, 0);

    return 0;
}

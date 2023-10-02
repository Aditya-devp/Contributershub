#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();
            cout << currentVertex << " ";

            for (int neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "Depth-First Traversal starting from vertex 0: ";
    g.DFS(0);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents infinity

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int id;
    int distance;

    Vertex(int _id, int _distance) : id(_id), distance(_distance) {}

    // Overload operator< to use in the priority queue
    bool operator<(const Vertex& other) const {
        return distance > other.distance;
    }
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size(); // Number of vertices in the graph
    vector<int> distance(n, INF); // Initialize distances to infinity
    vector<int> parent(n, -1); // Initialize parent array

    // Create a priority queue to store vertices and their distances
    priority_queue<Vertex> pq;

    // Initialize the distance of the source vertex
    distance[source] = 0;

    // Push the source vertex into the priority queue
    pq.push(Vertex(source, 0));

    while (!pq.empty()) {
        Vertex current = pq.top();
        pq.pop();
        int u = current.id;

        // Iterate over all adjacent vertices of the current vertex
        for (pair<int, int>& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Relaxation step
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(Vertex(v, distance[v]));
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << source << " to all other vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == INF) {
            cout << "Infinity" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }
}

int main() {
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);

    // Input the edges and their weights
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, source);

    return 0;
}

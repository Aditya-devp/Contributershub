#include <array>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <memory>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
    int64_t weight;
    int64_t flow; // Current flow through the edge

    Edge(int64_t weight_ = 0) : weight(weight_), flow(0) {}
};

class Graph {
  public:
    Graph(int64_t V) : NumVertices(V) {
        matrix = new Edge *[V];
        for (int64_t vert = 0; vert < V; vert++) {
            matrix[vert] = new Edge[V];
        }
    };
    ~Graph() { delete[] matrix; };
    void AddEdge(int64_t Src, int64_t Dst, int64_t Weight) {
        matrix[Src][Dst] = Edge(Weight);
    }

    int64_t maxFlow(int64_t source, int64_t sink) {
        for (int64_t i = 0; i < NumVertices; i++) {
            for (int64_t j = 0; j < NumVertices; j++) {
                matrix[i][j].flow = 0;
            }
        }
        while (true) {
            vector<int64_t> parent;
            if (!bfs(source, sink, parent)) {
                break;
            }
            int64_t bottleneck = INT64_MAX;
            for (int64_t v = sink; v != source; v = parent[v]) {
                int64_t u = parent[v];
                Edge *edges = matrix[u];
                if (matrix[u][v].flow < bottleneck) {
                    bottleneck = matrix[u][v].flow;
                }
            }
            for (int64_t v = sink; v != source; v = parent[v]) {
                int64_t u = parent[v];
                matrix[u][v].flow += bottleneck;
                matrix[u][v].weight -= bottleneck;
            }
        }
        int64_t maxflow = 0;
        for (int64_t i = 0; i < NumVertices; i++) {
            maxflow += matrix[source][i].flow;
        }
        return maxflow;
    }

  private:
    Edge **matrix;
    int64_t NumVertices;

    bool bfs(int64_t src, int64_t snk, vector<int64_t> &Parent) {
        vector<bool> visited(NumVertices);
        for (int64_t i = 0; i < NumVertices; i++) {
            visited[i] = false;
        }
        Parent[src] = -1;
        visited[src] = true;

        bool found = false;
        queue<int64_t> Q;
        Q.push(src);
        while (!Q.empty()) {
            int64_t u = Q.front();
            Q.pop();
            Edge *edges = matrix[u];
            for (int64_t i = 0; i < NumVertices; i++) {
                if (edges[i].weight != 0 && !visited[i]) {
                    visited[i] = true;
                    Parent[i] = u;
                    Q.push(i);
                    if (i == snk) {
                        found = true;
                    }
                }
            }
        }
        return found;
    }
};

int main(int argc, char *argv[]) {
    int64_t N;
    cin >> N;
    Graph graph(N);
    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j < N; j++) {
            int64_t wght;
            cin >> wght;
            graph.AddEdge(i, j, wght);
        }
    }
    auto begin = chrono::high_resolution_clock::now();
    for (int64_t i = 0; i < N; i++) {
        for (int64_t j = 0; j < N; j++) {
            graph.maxFlow(i, j);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::microseconds>(end - begin).count()
         << endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

// Define a structure to represent a node in the graph
struct Node {
    int x, y; // Coordinates of the node
    int g;    // Cost from the start node to this node
    int h;    // Heuristic cost from this node to the goal
    Node* parent; // Parent node in the path

    Node(int _x, int _y) : x(_x), y(_y), g(0), h(0), parent(nullptr) {}

    // Calculate the total cost (f) of the node
    int f() const {
        return g + h;
    }
};

// Custom comparison function for the priority queue
struct CompareNodes {
    bool operator()(const Node* a, const Node* b) const {
        return a->f() > b->f();
    }
};

// Function to calculate the heuristic (Manhattan distance) between two nodes
int heuristic(const Node* a, const Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Function to implement the A* algorithm
vector<Node*> astar(vector<vector<int>>& grid, Node* start, Node* goal) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<Node*> path;

    // Create a priority queue to store nodes to be explored
    priority_queue<Node*, vector<Node*>, CompareNodes> openSet;

    // Create a map to store the cost of reaching each node
    unordered_map<Node*, int> cost;

    // Initialize the open set with the start node
    openSet.push(start);

    // Initialize the cost of the start node to 0
    cost[start] = 0;

    while (!openSet.empty()) {
        // Get the node with the lowest f value from the open set
        Node* current = openSet.top();
        openSet.pop();

        // If the current node is the goal, reconstruct and return the path
        if (current == goal) {
            while (current != nullptr) {
                path.push_back(current);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Generate neighboring nodes
        vector<pair<int, int>> neighbors = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (const auto& offset : neighbors) {
            int newX = current->x + offset.first;
            int newY = current->y + offset.second;

            // Check if the neighbor is within bounds and is not an obstacle
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 0) {
                Node* neighbor = new Node(newX, newY);

                // Calculate the tentative g value
                int tentativeG = current->g + 1;

                // If this path is better than the previous one, update the neighbor
                if (cost.find(neighbor) == cost.end() || tentativeG < cost[neighbor]) {
                    neighbor->g = tentativeG;
                    neighbor->h = heuristic(neighbor, goal);
                    neighbor->parent = current;

                    // Add the neighbor to the open set and update the cost
                    openSet.push(neighbor);
                    cost[neighbor] = tentativeG;
                }
            }
        }
    }

    return path; // Return an empty path if no solution is found
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    Node* start = new Node(0, 0);
    Node* goal = new Node(4, 4);

    vector<Node*> path = astar(grid, start, goal);

    if (path.empty()) {
        cout << "No path found!" << endl;
    } else {
        cout << "Path found:" << endl;
        for (const Node* node : path) {
            cout << "(" << node->x << ", " << node->y << ")" << endl;
        }
    }

    // Clean up memory
    for (Node* node : path) {
        delete node;
    }

    return 0;
}

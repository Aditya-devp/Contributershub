//* https://leetcode.com/problems/critical-connections-in-a-network/description/
//* https://youtu.be/qrAub5z8FeA

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, 
            vector<int>& low, vector<int>& tin, vector<vector<int>>& bridges){
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;

        for(auto adjNode : adj[node]){
            // skip parent
            if(adjNode == parent){
                continue;
            }

            // if not visited yet
            if(!vis[adjNode]){
                dfs(adjNode, node, adj, vis, low, tin, bridges);

                // updating low of node
                low[node] = min(low[node], low[adjNode]);

                // if the adjNode cannot reach node via any other path, then it's a bridge
                if(low[adjNode] > tin[node]){
                    bridges.push_back({adjNode, node});
                }
            }

            // if already visited that means another path exists to reach node via this adjNode that is not parent of this node
            else{
                // update low of node with minimum of low of adjNode and node

                low[node] = min(low[node], low[adjNode]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        // creating graph
        vector<vector<int>> adj(n);
        for(auto it : connections){
            // bidirectional
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int>> bridges; // stores bridges
        vector<int> vis(n, 0), low(n), tin(n);

        dfs(0, -1, adj, vis, low, tin, bridges);

        return bridges;
    }
};
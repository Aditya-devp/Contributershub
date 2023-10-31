//* https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1
//* https://youtu.be/qrAub5z8FeA

class Solution{
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, 
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
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here

        vector<vector<int>> bridges; // stores bridges
        vector<int> vis(V, 0), low(V), tin(V);
        
        //* Ensuring Connected Components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, low, tin, bridges);
            }
        }
        
        for(auto bridge : bridges){
            if((bridge[0] == c && bridge[1] == d) || (bridge[0] == d && bridge[1] == c)){
                return 1;
            }
        }
        
        return 0;
    }
};
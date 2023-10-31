//* https://practice.geeksforgeeks.org/problems/articulation-point-1/1
//* https://youtu.be/j1QDfU21iZk

class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> adj[], vector<int>& vis, 
            vector<int>& low, vector<int>& tin, vector<int>& mark){
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;

        for(auto adjNode : adj[node]){
            // skip parent
            if(adjNode == parent){
                continue;
            }

            // if not visited yet
            if(!vis[adjNode]){
                dfs(adjNode, node, adj, vis, low, tin, mark);

                // updating low of node
                low[node] = min(low[node], low[adjNode]);

                // if the adjNode can only be reached via node, then it's a articulation point
                if(low[adjNode] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                
                child++;
            }

            // if already visited that means another path exists to reach node via this adjNode that is not parent of this node
            else{
                // update low of node with minimum of tin of adjNode and low of node

                low[node] = min(low[node], tin[adjNode]);
            }
        }
        
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> vis(V, 0), mark(V, 0); // mark-> marks the articulation points
        vector<int> tin(V), low(V);
        
        // ensuring connected components->
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, low, tin, mark);
            }
        }
        
        
        vector<int> ans;
        for(int i = 0; i < V; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0){
            return {-1};
        }
        
        return ans;
    }
};
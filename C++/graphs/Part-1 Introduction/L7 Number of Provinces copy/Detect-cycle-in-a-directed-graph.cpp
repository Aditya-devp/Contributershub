//* https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
//* https://youtu.be/9twcmtQj4DU

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V, 0), pathvis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& path){
        vis[node] = 1;
        path[node] = 1;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, path) == true){
                    return true;
                }
                
            }
            else if(path[adjNode]){
                return true;
            }
        }
        
        path[node] = 0;
        return false;
    }
};
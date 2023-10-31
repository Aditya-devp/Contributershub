class Solution {
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V, 0);
        
        // connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                // using bfs->
                if(bfs(i, adj, vis)){
                    return true;
                }
                
                
            }
        }
        
        return false;
    }
    
    bool bfs(int src, vector<int> adj[], vector<int>& vis){
        
        queue<pair<int,int>> q;
        q.push({src, -1});
        vis[src] = 1;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int i : adj[node]){
                if(!vis[i]){
                    q.push({i, node});
                    vis[i] = 1;
                }
                else if(parent != i){
                    // if the visited one isnt the oparent then there's cycle 
                    return true;
                }
            }
        }
        
        return false;
    }
    
};
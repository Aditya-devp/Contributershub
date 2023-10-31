//* https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
//* Using DFS-> https://youtu.be/uRbJ1OF9aYM
//* Using BFS(Kahn's Algo)-> https://youtu.be/2gtg3VsDGyc

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        //* using DFS
        // return using_DFS(V, adj);
        
        //* Using BFS (Kahn's Algo)
        return using_BFS(V, adj);
    }
    
    
    vector<int> using_DFS(int V, vector<int> adj[]){
        vector<int> vis(V, 0), pathvis(V, 0), check(V, 0), ans;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    bool dfs(int node, vector<int> adj[], vector<int>& vis, 
            vector<int>& path, vector<int>& check){
                
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                if(dfs(adjNode, adj, vis, path, check) == true){
                    check[adjNode] = 0;
                    return true;
                }
            }
            else if(path[adjNode]){
                check[adjNode] = 0;
                return true;
            }
        }
        
        check[node] = 1;
        path[node] = 0;
        return false;
    }
    
    
    vector<int> using_BFS(int n, vector<int> graph[]) {

        vector<vector<int>> adj(n);
        // reversing the edge directions
        for(int i = 0; i < n; i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }

        return using_kahnAlgo(n, adj);
    }
    //* BFS
    vector<int> using_kahnAlgo(int V, vector<vector<int>> adj){
        
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++){
            for(int adjNode : adj[i]){
                indegree[adjNode]++; // calculating indegree of every node
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i); // pushing starting sources
            }
        }
        
        vector<int> safeNodes;
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            safeNodes.push_back(node);
            
            for(int adjNode : adj[node]){
                indegree[adjNode]--;
                
                // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        // sort the seqeunce
        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};
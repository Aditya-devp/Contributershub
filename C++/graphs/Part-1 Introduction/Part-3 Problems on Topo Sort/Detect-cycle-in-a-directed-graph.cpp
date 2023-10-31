//* https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
//* Using DFS-> https://youtu.be/9twcmtQj4DU
//* Using BFS (Kahn's Algorithm)-> https://youtu.be/iTBaI90lpDQ

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        // return using_dfs(V, adj);
        
        return using_bfs_kahnAlgo(V, adj);
    }
    bool using_dfs(int V, vector<int> adj[]){
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
    
    bool using_bfs_kahnAlgo(int V, vector<int> adj[]){
        
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

        int cnt;
        while(!q.empty()){
            int node = q.front(); q.pop();

            cnt++;

            for(int adjNode : adj[node]){
                indegree[adjNode]--;

                // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        return (cnt == V ? false : true);
    }
};
//* https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph
//* https://youtu.be/Qzf1a--rhp8

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& ans, vector<int>& vis){
        
        ans.push_back(node);
        vis[node] = 1;
        
        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i, adj, ans, vis);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans, vis(V);
        vis[0] = 1;
        
        dfs(0, adj, ans, vis);
        
        return ans;
    }
};
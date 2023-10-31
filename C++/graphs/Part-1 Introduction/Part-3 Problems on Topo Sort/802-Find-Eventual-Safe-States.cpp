//* https://leetcode.com/problems/find-eventual-safe-states/
//* Using DFS ->https://youtu.be/uRbJ1OF9aYM
//* Using Kahn's Algo (Topo sort BFS) -> https://youtu.be/2gtg3VsDGyc

//* Using DFS-> TLE
/*
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> vis(V, 0), pathvis(V, 0), check(V, 0), ans;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathvis, check);
            }
        }
        
        for(int i = 0; i < V; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        
        return ans;
    }

    bool dfs(int node, vector<vector<int>> adj, vector<int>& vis, 
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
};
*/

// //* DFS Editorial->
// class Solution {
// public:
//     bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& inStack) {
//         // If the node is already in the stack, we have a cycle.
//         if (inStack[node]) {
//             return true;
//         }
//         if (visit[node]) {
//             return false;
//         }
//         // Mark the current node as visited and part of current recursion stack.
//         visit[node] = true;
//         inStack[node] = true;
//         for (auto neighbor : adj[node]) {
//             if (dfs(neighbor, adj, visit, inStack)) {
//                 return true;
//             }
//         }
//         // Remove the node from the stack.
//         inStack[node] = false;
//         return false;
//     }

//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> adj(n);

//         for (int i = 0; i < n; i++) {
//             for (auto node : graph[i]) {
//                 adj[i].push_back(node);
//             }
//         }

//         vector<bool> visit(n), inStack(n);

//         for (int i = 0; i < n; i++) {
//             dfs(i, adj, visit, inStack);
//         }

//         vector<int> safeNodes;
//         for (int i = 0; i < n; i++) {
//             if (!inStack[i]) {
//                 safeNodes.push_back(i);
//             }
//         }
//         return safeNodes;
//     }


//* Using Kahn's Algo (Topo sort BFS) -> https://youtu.be/2gtg3VsDGyc
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n  = graph.size();

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
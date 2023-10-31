//* https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
//* https://youtu.be/R6uoSjZ2imo

class Solution{
private:
    void dfs_sort(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs_sort(adjNode, adj, vis, st);
            }
        }
        
        st.push(node);
    }
    
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis);
            }
        }
    }
    
public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj){
        //code here
        
        //* Step-1-> Sort according to finishing time
        stack<int> st;
        vector<int> vis(V, 0);
        // also ensuring connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs_sort(i, adj, vis, st);
            }
        }
        
        
        //* Step-2-> Reversing the edges
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++){
            
            vis[i] = 0;
            
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        
        int scc = 0;
        //* Step-3-> Do DFS
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs(node, adjT, vis);
            }
        }
        
        
        return scc;
    }
};
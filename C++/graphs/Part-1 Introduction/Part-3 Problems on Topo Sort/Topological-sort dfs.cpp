//* https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
//* https://youtu.be/5lZ0iJMrUMk

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here

        vector<int> vis(V, 0);
        stack<int> st;
    
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
	}
	
	void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        
        for(int adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, st);
            }
        }
        
        st.push(node);
	}
};
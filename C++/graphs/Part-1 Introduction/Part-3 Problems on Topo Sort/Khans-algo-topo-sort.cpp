//* https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
//* Using simple toposort algo-> https://youtu.be/5lZ0iJMrUMk
//* Using Kahn's Algorithm-> https://youtu.be/73sneFXuTEg

class Solution
{
public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here

	    //* Using simple toposort Algorithm
	    // return topo(V, adj);

	    //* Using Kahn's Algorithm
        return using_kahnAlgo(V, adj);
	}
	
	vector<int> using_kahnAlgo(int V, vector<int> adj[]){

        vector<int> indegree(V, 0);
        for(int i = 0 ;i < V; i++){
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

        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();

            ans.push_back(node);

            for(int adjNode : adj[node]){
                indegree[adjNode]--;

	            // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }
	
	vector<int> topo(int V, vector<int> adj[]){
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
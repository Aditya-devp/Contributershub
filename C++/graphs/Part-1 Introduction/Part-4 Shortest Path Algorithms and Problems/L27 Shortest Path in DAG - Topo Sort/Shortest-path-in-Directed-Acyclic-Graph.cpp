//* https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
//* Using TopoSort -> https://youtu.be/ZUFQfFaU-8U

class Solution {
public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        //* Method-1
        topoSort topoObj;
        return topoObj.using_topoSort(N, M, edges);
        
    }
    
    class topoSort{
    public:
        vector<int> using_topoSort(int N, int M, vector<vector<int>>& edges){
            // create graph
            vector<pair<int, int>> adj[N];
            for(int i = 0; i < M; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                
                adj[u].push_back({v, wt});
            }
            
            // toposort of graph
            stack<int> st;
            vector<int> vis(N, 0);
            for(int i = 0; i < N; i++){
                if(!vis[i]){
                    topo(i, adj, vis, st);
                }   
            }
            
            // calculating distance from source 0
            vector < int > dist(N, 1e9);
            dist[0] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                
                for(auto adjNode : adj[node]){
                    
                    int v = adjNode.first;
                    int wt = adjNode.second;
                    
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
            
            for(int i = 0; i < N; i++){
                if(dist[i] == 1e9){
                    dist[i] = -1;
                }
            }
            
            return dist;
        }
        void topo(int node, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st){
            vis[node] = 1;
            
            for(auto it : adj[node]){
                int v = it.first;
                if(!vis[v]){
                    topo(v, adj, vis, st);
                }
            }
            
            st.push(node);
        }
    };
};
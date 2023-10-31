//* https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
//* Using BruteForce-> https://youtu.be/C4gxoTaI71U

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        // Brute Force->
        BruteForce obj1;
        return obj1.brute(edges, N, M, src);
    }
    
    class BruteForce{
    public:
        vector<int> brute(vector<vector<int>>& edges, int N, int M, int src){
            // create graph
            vector<int> adj[N];
            for(int i = 0; i < M; i++){
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }
            
            // calculating distances
            vector<int> dist(N, 1e9);
            dist[src] = 0;
            
            queue<int> q;
            q.push(src);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                
                for(int adjNode : adj[node]){
                    if(dist[node] + 1 < dist[adjNode]){
                        dist[adjNode] = dist[node] + 1;
                        
                        q.push(adjNode);
                    }
                }
            }
            
            
            // marking unreachable nodes with -1
            for(int i = 0; i < N; i++){
                if(dist[i] == 1e9){
                    dist[i] = -1;
                }
            }
            
            return dist;
        }
    };
};
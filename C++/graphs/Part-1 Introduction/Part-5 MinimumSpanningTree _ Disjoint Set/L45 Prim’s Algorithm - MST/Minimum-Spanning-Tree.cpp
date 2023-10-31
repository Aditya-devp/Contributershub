//* https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
//* using Prims Algo-> https://youtu.be/mJcZjjKzeqk

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        // Using Prim's Algorithm
        return using_PrimsAlgo(V, adj);
    }
    
    int using_PrimsAlgo(int V, vector<vector<int>> adj[]){
        // {wt, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        vector<int> vis(V, 0);
        
        int sum = 0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            
            // skip if already visited
            if(vis[node] == 1){
                continue;
            }
            
            vis[node] = 1; // mark visited
            sum += wt; // add edge wt
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edw = it[1];
                
                if(!vis[adjNode]){
                    pq.push({edw, adjNode});
                }
            }
        }
        
        return sum;
    }
};
//* https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
//* https://youtu.be/V6H1qAeB-l4

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //* Using Priority-Queue
        return using_PQ(V, adj, S);
    }
    
    // Using PQ->
    vector<int> using_PQ(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int>, vector<pair<int, int>>, 
        greater<pair<int,int>>> pq;
        
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];
                
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};
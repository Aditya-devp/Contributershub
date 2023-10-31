class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> shortestPathPrint(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //* Using Priority-Queue
        return using_PQ(V, adj, S);
    }
    
    // Using PQ->
    vector<int> using_PQ(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        
        vector<int> parent(V);
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }

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
                    parent[adjNode] = node;
                }
            }
        }

        if(dist[V-1] != 1e9){
            return {-1};
        }

        vector<int> path;
        int node V-1;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        return path;
    }
};
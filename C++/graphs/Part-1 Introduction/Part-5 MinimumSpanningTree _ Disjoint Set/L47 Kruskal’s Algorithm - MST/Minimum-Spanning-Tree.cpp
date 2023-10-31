//* https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree
//* using Prims Algo-> https://youtu.be/mJcZjjKzeqk
//* using Kruskal's Algo using Disjoint set-> https://youtu.be/DMnDM_sxVig


//* <------------------------- Disjoint Set Util Starts ------------------------->

class DisjointSet{
public:
    vector<int> parent, rank, size;

    // constructor
    DisjointSet(int n){
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; ++i){
            parent[i] = i;
        }
    }

    // find ultimate parent
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]); // does path compression as well
    }

    // union by rank
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u); // calculate ultimate parent of u
        int ulp_v = findUPar(v); // calculate ultimate parent of v

        // if both have same ULP, means both are in same set
        if(ulp_u == ulp_v){
            return;
        }

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // union by size
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u); // calculate ultimate parent of u
        int ulp_v = findUPar(v); // calculate ultimate parent of v

        // if both have same ULP, means both are in same set
        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

//* <------------------------- Disjoint Set Util Ends ------------------------->


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        // Using Prim's Algorithm
        // return using_PrimsAlgo(V, adj);
        
        // Using Kruskal's Algorithm
        return using_KruskalAlgo(V, adj);
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
    
    int using_KruskalAlgo(int V, vector<vector<int>> adj[]){
        
        // {edge_weight, {u, v}}
        vector<pair<int, pair<int,int>>> edges;
        for(int i = 0; i < V; i++){
            int node = i;
            
            for(auto it : adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        // sort according to increasing edge weights
        sort(begin(edges), end(edges));
        
        DisjointSet ds(V); // data structure created
        
        int mstWt = 0;
        
        for(auto it : edges){
            int edw = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u) != ds.findUPar(v)){
                ds.unionBySize(u, v);
                mstWt += edw;
            }
        }
        
        return mstWt;
    }
};
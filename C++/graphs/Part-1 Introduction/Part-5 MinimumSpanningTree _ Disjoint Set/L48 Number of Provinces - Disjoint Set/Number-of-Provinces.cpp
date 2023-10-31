//* https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
//* Using DFS-> https://youtu.be/ACzkVtewUYA
//* Using Disjoint Set-> https://youtu.be/ZGr5nX-Gi6Y

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Creating Adjacency List
        vector<vector<int>> adjList(V);
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        // code here
        
        // return using_bfs(adjList, V);
        
        // return using_dfs(adjList, V);
        
        //* Using Disjoint Set Approach->
        Disjoint_Set_Algo obj3;
        return obj3.using_disjoint_set(adj);
    }
    
    int using_bfs(vector<vector<int>>& adjList, int V){
        
        int provinces = 0;
        vector<int> vis(V);

        // ensuring connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(auto it : adjList[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }

                provinces++;
            }
        }

        return provinces;
    }

    int using_dfs(vector<vector<int>>& adjList, int V){

        int provinces = 0;
        vector<int> vis(V);

        // ensuring connected components
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, vis, adjList);
                provinces++;
            }
        }

        return provinces;
    }
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adjList){
        vis[node] = 1;
        
        for(auto i : adjList[node]){
            if(!vis[i]){
                dfs(i, vis, adjList);
            }
        }
    }
    
    
    
    class Disjoint_Set_Algo{
    public:
        int using_disjoint_set(vector<vector<int>>& edges){
            int n = edges.size();
            
            DisjointSet ds(n);
            
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // edge exists
                    if(edges[i][j] == 1){
                        ds.unionBySize(i, j);
                    }
                }
            }

            int provinces = 0;
            for(int i = 0; i < n; i++){
                if(ds.parent[i] == i){
                    provinces++;
                }
            }

            return provinces;
        }
    };

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
};
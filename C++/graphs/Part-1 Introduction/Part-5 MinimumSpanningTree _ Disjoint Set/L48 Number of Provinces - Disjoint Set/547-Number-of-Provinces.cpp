//* https://leetcode.com/problems/number-of-provinces/description/
//* Using DFS-> https://youtu.be/ACzkVtewUYA
//* Using Disjoint Set-> https://youtu.be/ZGr5nX-Gi6Y

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        // Using BFS Traversal
        // BFSAlgo obj1;
        // return obj1.using_bfs(isConnected);
        
        // Using DFS Traversal
        // DFSAlgo obj2;
        // return obj2.using_dfs(isConnected);

        //* Using Disjoint Set Approach->
        Disjoint_Set_Algo obj3;
        return obj3.using_disjoint_set(isConnected);
    }


    class BFSAlgo{
    public:
        int using_bfs(vector<vector<int>>& isConnected){
        
            // Creating Adjacency List
            int n = isConnected.size();
            vector<vector<int>> adj(n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(isConnected[i][j] == 1 && i != j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            int provinces = 0;
            vector<int> vis(n);

            // ensuring connected components
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    queue<int> q;
                    q.push(i);
                    vis[i] = 1;

                    while(!q.empty()){
                        int node = q.front();
                        q.pop();

                        for(auto it : adj[node]){
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
    };
    
    class DFSAlgo{
    public:
        int using_dfs(vector<vector<int>>& isConnected){
            // Creating Adjacency List
            int n = isConnected.size();
            vector<vector<int>> adj(n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(isConnected[i][j] == 1 && i != j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }

            int provinces = 0;
            vector<int> vis(n);

            // ensuring connected components
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    dfs(i, vis, adj);
                    provinces++;
                }
            }

            return provinces;
        }
        void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
            vis[node] = 1;
            
            for(auto i : adj[node]){
                if(!vis[i]){
                    dfs(i, vis, adj);
                }
            }
        }
    };

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
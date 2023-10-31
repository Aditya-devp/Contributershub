//* https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph
//* https://youtu.be/FYrl7iz9_ZU

class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        int extraEdges = 0, totalEdges = edge.size();

        DisjointSet ds(n);

        for(auto it : edge){
            int u = it[0];
            int v = it[1];

            // if aldready connected, then they should have same ultimate parent
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }


        int cntComponents = 0; // number of components
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                cntComponents++;
            }
        }

        int reqEdges = cntComponents - 1;// edges required to connect to disconnected componenets

        if(extraEdges >= reqEdges){
            return reqEdges;
        }

        return -1; // not possible
    }
    
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
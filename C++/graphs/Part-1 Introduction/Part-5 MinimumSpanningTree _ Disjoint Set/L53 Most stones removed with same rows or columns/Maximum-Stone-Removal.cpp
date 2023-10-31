//* https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1
//* https://youtu.be/OwMNX8SPavM

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here

        int maxRow = 0, maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow, it[0]); // till where stones are present
            maxCol = max(maxCol, it[1]); // till where stones are present
        }

        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int,int> stoneNodes; // keeps track of nodes where stones are present

        for(auto it : stones){
            int nodeRow = it[0];    // row node number = row number
            int nodeCol = it[1] + maxRow + 1; // column node number = colmnNumber + maxRow + 1

            ds.unionBySize(nodeRow, nodeCol);

            stoneNodes[nodeRow] = 1; // marking, that stone is present in this row node
            stoneNodes[nodeCol] = 1; // marking, that stone is present in this column node
        }

        int cnt = 0; // number of components present
        // traversing components
        for(auto it : stoneNodes){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }

        return n - cnt;
    }
    
    //* <------------------------- Disjoint Set Util Starts ------------------------->

    class DisjointSet{
    public:
        vector<int> parent, rank, size;

        // constructor
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1);

            for(int i = 0; i <= n; ++i){
                parent[i] = i;
                size[i] = 1;
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
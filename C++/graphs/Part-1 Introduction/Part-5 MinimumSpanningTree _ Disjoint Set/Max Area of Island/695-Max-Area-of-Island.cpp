class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        DisjointSet ds(n * m); // n * m nodes in total
        
        int mxSize = 0;
        
        // 4 directions-> up, right, bottom, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        int cntZero = 0; // edge case-> when all 0's-> cntZero == n*m

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                
                if(grid[row][col] == 0){
                    cntZero++;
                    continue;
                }

                int nodeNo = row*m + col;

                for(int ind = 0; ind < 4; ind++){
                    int nRow = row + dr[ind];
                    int nCol = col + dc[ind];

                    if(isValid(nRow, nCol, n, m) && grid[nRow][nCol] == 1){
                        int adjNodeNo = nRow*m + nCol;

                        // if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                        //     ds.unionBySize(nodeNo, adjNodeNo);
                        // }
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }

                // current component size
                mxSize = max(mxSize, ds.size[ds.findUPar(nodeNo)]);
            }
        }

        return cntZero == n*m ? 0 : mxSize; 
    }
    int coordinatesToNodeNo(int row, int col, int n){
        return (row * n) + col;
    }
    bool isValid(int adjr, int adjc, int n, int m){
        return (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m);
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
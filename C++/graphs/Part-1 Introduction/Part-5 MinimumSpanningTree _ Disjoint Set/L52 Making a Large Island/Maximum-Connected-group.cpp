//* https://practice.geeksforgeeks.org/problems/maximum-connected-group/1
//* Using DSU -> https://youtu.be/lgiz0Oup6gM

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

class Solution {
public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        
        DisjointSet ds(n * n); // n*n nodes

        // 4 directions-> up, right, bottom, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};        
        
        //* STEP-1
        // Creating islands(components) from existing land cells->
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                
                // if ceel is not land
                if(grid[row][col] == 0){
                    continue;
                }

                // else->
                // check in all 4 directions for other lands to connect
                for(int ind = 0; ind < 4; ind++){
                    int nRow = row + dr[ind];
                    int nCol = col + dc[ind];

                    // if valid coordinates and is also a land cell
                    if(isValid(nRow, nCol, n, n) && grid[nRow][nCol] == 1){
                        // node number = (row number) * (number of columns) + (column number)
                        int nodeNo = (row) * n + col;
                        int adjNodeNo = (nRow) * n + nCol;

                        // connecting adjacent nodes (doesn't matter if already connected or not, as it compares ultimate parent, if different then connects, else does nothing)
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        //* STEP-2
        int mx = 0; // stores maximum size
        // reaplacing 0 with 1 and finding max size island
        for(int row = 0; row < n; row++){
            for(int col = 0;  col < n; col++){
                // if land, then skip, as we are lookinh for 0
                if(grid[row][col] == 1){
                    continue;
                }

                // else-> found 0
                // capture sizes of existing islands in all 4 directions
                set<int> components; // stores parent node of different components in up, right, left, down directions
                for(int ind = 0; ind < 4; ind++){
                    int nRow = row + dr[ind];
                    int nCol = col + dc[ind];

                    // valid coordinate checking
                    if(isValid(nRow, nCol, n, n)){
                        // land exists or not
                        if(grid[nRow][nCol] == 1){
                            int adjNodeNo = nRow * n + nCol;
                            components.insert(ds.findUPar(adjNodeNo));
                        }
                    }
                }

                int setTotal = 0;
                for(auto it : components){
                    setTotal += ds.size[it]; // size array of ds stores the size of componenet whose parent node is it
                }

                mx = max(mx, setTotal + 1); // also including current 0 converted to 1
            }
        }

        // Edge Case Checking->
        // if no 0 present int grid, means all are land cells
        for(int cellNo = 0; cellNo < n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
            // all cells will have same parent, and only 1 component as a whole
        }


        return mx;
    }
    bool isValid(int adjr, int adjc, int n, int m){
        return (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m);
    }
};
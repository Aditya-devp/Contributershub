//* https://practice.geeksforgeeks.org/problems/number-of-islands/1
//* Using DSU -> https://youtu.be/Rn6B-Q4SNyA

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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        DisjointSet ds(n * m); // n * m nodes in total
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        int cntIslands = 0;
        
        // 4 directions-> up, right, bottom, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int k = operators.size();
        vector<int> ans(k);
        
        for(int i = 0; i < k; i++){
            
            int row = operators[i][0];
            int col = operators[i][1];
            
            // if already visited
            if(vis[row][col] == 1){
                ans[i] = cntIslands;
                continue;
            }
            
            
            vis[row][col] = 1; // mark visited
            cntIslands++;
            
            int nodeNo = coordinatesToNodeNo(row, col, m); // number of node (or id of cell as a node number) 
            
            // checking for any existing island in all 4 directions
            // and merging them if exists, thus decreasing cnt of islands
            for(int j = 0; j < 4; j++){
                int adjRow = row + dr[j];
                int adjCol = col + dc[j];
                
                if(isValid(adjRow, adjCol, n, m)){
                    
                    if(vis[adjRow][adjCol] == 1){
                        int adjNodeNo = coordinatesToNodeNo(adjRow, adjCol, m); // number of adjacent node
                        
                        int ulp_currNode = ds.findUPar(nodeNo); // ultimate parent of node
                        int ulp_adjNode = ds.findUPar(adjNodeNo); // ultimate parent of adjacent node
                        
                        // if both have different parent, then merge them, and decrease cnt of islands
                        if(ulp_currNode != ulp_adjNode){
                            ds.unionBySize(nodeNo, adjNodeNo);
                            
                            cntIslands--;
                        }
                    }
                }
            }
            
            ans[i] = cntIslands;
        }
        
        return ans;
    }
    
    int coordinatesToNodeNo(int row, int col, int m){
        return (row * m) + col;
    }
    bool isValid(int adjr, int adjc, int n, int m){
        return (adjr >= 0 && adjr < n && adjc >= 0 && adjc < m);
    }
};
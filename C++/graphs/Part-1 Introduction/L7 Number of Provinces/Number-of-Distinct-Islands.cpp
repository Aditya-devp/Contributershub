//* https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
//* https://youtu.be/7zmgQSJghpo

class Solution {
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        return numIslands(grid);
    }
    
    int numIslands(vector<vector<int>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // for storing shapes
        set<vector<pair<int, int>>> st;

        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    vector<pair<int, int>> vec;
                    dfs(row, col, grid, vis, vec, row, col, n, m);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, 
            vector<pair<int, int>>& vec, int baseRow, int baseCol, int n, int m){
        vis[row][col] = 1;
        vec.push_back({row - baseRow, col - baseCol});

        // directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Checking in all 8 directions
        for(int i = 0; i < 8; i++){

            int nRow = row + dr[i];
            int nCol = col + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
            && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                dfs(nRow, nCol, grid, vis, vec, baseRow, baseCol, n, m);
            }
        }
    }
};
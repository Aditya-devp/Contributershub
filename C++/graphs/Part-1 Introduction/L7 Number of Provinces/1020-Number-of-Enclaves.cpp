//* https://leetcode.com/problems/number-of-enclaves/description/
//* https://youtu.be/rxKcepXQgU4

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        return solve(grid);
    }

    //* https://leetcode.com/problems/surrounded-regions/
    int solve(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // checking boundaries
        for(int j = 0; j < m; j++){
            // first row
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0, j, grid, vis, dr, dc, n, m);
            }
            // last row
            if(grid[n-1][j] == 1 && !vis[n-1][j]){
                dfs(n-1, j, grid, vis, dr, dc, n, m);
            }
        }
        for(int i = 0; i < n; i++){
            // first column
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, grid, vis, dr, dc, n, m);
            }
            // last column
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i, m-1, grid, vis, dr, dc, n, m);
            }
        }

        
        int cnt = 0;
        // updating grid
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(int row, int col, vector<vector<int>>& grid, 
            vector<vector<int>>& vis, int dr[], int dc[], int n, int m){
        
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                
                dfs(nRow, nCol, grid, vis, dr, dc, n, m);
            }
        }
    }
};



class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> grid, vector<vector<int>> &vis,int n, int m ){
        vis[i][j] = 1;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int it = 0;it<4;it++){
            int nr = dr[it]+i;
            int nc = dc[it]+j;

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] ==0 && grid[nr][nc] == 1 ){
                dfs(nr, nc, grid, vis, n, m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid [0].size();

        vector<vector<int>> vis(0, vector<int> (m,0));
        int ans = 0;
        
        
        // traversal boundries
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    dfs(i, j, grid, vis, n, m);
                }
                }
            }
            }
        // addition to ans

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] ==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
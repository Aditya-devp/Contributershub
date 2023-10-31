//* https://leetcode.com/problems/number-of-islands/
//* https://youtu.be/muncqlKJrH0

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                   
                    dfs(row, col, grid, vis, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;

        // directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        // Checking in all 4 directions
        for(int i = 0; i < 4; i++){

            int nRow = row + dr[i];
            int nCol = col + dc[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
            && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                dfs(nRow, nCol, grid, vis, n, m);
            }
        }
    }
};


or bfs one:

class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,vector<vector<int>> &vis ){
        queue<pair<int,int>> q;
        int n = grid.size();
        int m =grid[0].size();
        vis[row][col] = 1;
        q.push({row,col});
        while(!q.empty()){
            int rows = q.front().first;
            int cols = q.front().second;
            q.pop();
            for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1; delcol<=1;delcol++){
                     int nr = rows+delrow;
                     int nc = cols+delcol;
                    // traverse sides ones
                     if(delrow!= 0 && delcol !=0){
                         continue;
                     }
                     if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == '1'){
                         vis[nr][nc] = 1;
                         q.push({nr, nc});
                     }
                }
            }
        }

        
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> ans;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int c = 0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, grid, vis);
                    c++;
                }
            }
        }
        return c;
    }   
};
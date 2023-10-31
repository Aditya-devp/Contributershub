//* https://leetcode.com/problems/rotting-oranges/
//* https://youtu.be/yf3oUhkvqA0

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        return solve(n, m, grid);
        
        
    }

    int solve(int n, int m , vector<vector<int>>& grid){
        
        int totalFresh = 0;
        queue<pair<pair<int,int>, int>> q; // {{row, col}, time};
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1){
                    totalFresh++;
                }
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int tm = 0; // max time;
        int rottened = 0;
        // BFS
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int t = node.second;
            
            tm = max(tm, t);
            
            for(int i = 0;  i < 4; i++){
                
                int nRow = r + dr[i];
                int nCol = c + dc[i];
            
                if(isValid(nRow, nCol, n, m, grid, vis)){
                    
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, t+1});
                    rottened++;
                }
            }
        }
        
        return (rottened == totalFresh ? tm : -1);
    }
    
    
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& grid,
                    vector<vector<int>>& vis){
        
        return (row >= 0 && row < n && col >= 0 && col < m
                && grid[row][col] == 1 && !vis[row][col]);                    
    }
};
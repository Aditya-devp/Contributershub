//* https://leetcode.com/problems/surrounded-regions/
//* https://youtu.be/BtdgAys4yMk

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // checking boundaries
        for(int j = 0; j < m; j++){
            // first row
            if(board[0][j] == 'O' && !vis[0][j]){
                dfs(0, j, board, vis, dr, dc, n, m);
            }
            // last row
            if(board[n-1][j] == 'O' && !vis[n-1][j]){
                dfs(n-1, j, board, vis, dr, dc, n, m);
            }
        }
        for(int i = 0; i < n; i++){
            // first column
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, vis, dr, dc, n, m);
            }
            // last column
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, board, vis, dr, dc, n, m);
            }
        }

        
        // updating board
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int row, int col, vector<vector<char>>& board, 
            vector<vector<int>>& vis, int dr[], int dc[], int n, int m){
        
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int nRow = row + dr[i];
            int nCol = col + dc[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                && board[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                
                dfs(nRow, nCol, board, vis, dr, dc, n, m);
            }
        }
    }
};
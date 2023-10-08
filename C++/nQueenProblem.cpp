//problem link: https://leetcode.com/problems/n-queens/description/
void solve(int col,vector<string> board,vector<vector<string>> &ans,int n,vector<int> left,vector<int> u,vector<int> l){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row =0; row<n; row++){
            if(left[row]==0 && l[row+col]==0 && u[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                l[row+col]=1;
                u[n-1+col-row]=1;
                solve(col+1,board,ans,n,left,u,l);
                board[row][col]='.';
                left[row]=0;
                l[row+col]=0;
                u[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i=0; i<n; i++){
            board[i] = s;
        }
        vector<int> left(n,0);
        vector<int> udia(2*n-1,0);
        vector<int> ldia(2*n-1,0);
        solve(0,board,ans,n,left,udia,ldia);
        return ans;
    }

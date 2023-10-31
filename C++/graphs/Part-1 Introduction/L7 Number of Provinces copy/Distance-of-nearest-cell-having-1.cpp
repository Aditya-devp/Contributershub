class Solution 
{
public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>>grid)
	{
	    // Code here
        
	    //* using BFS
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // {{row, col}, steps}
        queue<pair<pair<int,int>, int>> q;

        // pushing Multi-sources
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first.first;
            int c = node.first.second;
            int steps = node.second;

            dist[r][c] = steps;

            for(int i = 0; i < 4; i++){
                int nRow = r + dr[i];
                int nCol = c + dc[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps+1});
                }
            }
        }

        return dist;
	}
};
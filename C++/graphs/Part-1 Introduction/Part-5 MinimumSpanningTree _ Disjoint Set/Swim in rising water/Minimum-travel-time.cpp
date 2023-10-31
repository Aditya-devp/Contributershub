//* https://practice.geeksforgeeks.org/problems/minimum-travel-time/1

class Solution {
public:
    int Solve(int n, vector<vector<int>>& grid) {
        // code here
        
        // using djikstra's

        return using_djikstras(grid);
    }
    
    int using_djikstras(vector<vector<int>>& grid){

        // {time, {row, col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        int n = grid.size();
        // vector<vector<int>> dist(n, vector<int> (n, 1e9));
        // dist[0][0] = 0;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        int ans = 1e9;

        while(!pq.empty()){
            auto temp = pq.top(); pq.pop();
            int time = temp.first;
            int row = temp.second.first;
            int col = temp.second.second;
            
            if(row == n-1 && col == n-1){
                ans = min(ans, time);
                break;
            }

            for(int i = 0; i < 4; i++){
                int nRow = row + dr[i];
                int nCol = col + dc[i];

                if(isValid(nRow, nCol, n) && !vis[nRow][nCol]){
                    int nTime = grid[nRow][nCol];
                    int tReq = max(time, nTime);

                    pq.push({tReq, {nRow, nCol}});

                    vis[nRow][nCol] = 1;
                }
            }
        }


        return ans;
    }
    bool isValid(int row, int col, int n){
        return row >= 0 && col >= 0 && row < n&& col < n;
    }
};
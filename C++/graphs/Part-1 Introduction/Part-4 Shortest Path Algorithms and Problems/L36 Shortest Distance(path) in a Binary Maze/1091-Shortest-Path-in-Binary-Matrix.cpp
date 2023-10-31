//* https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
//* https://youtu.be/U5Mw4eyUmw4

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // unreachable
        if(grid[0][0] == 1){
            return -1;
        }

        // Edge Case-> when source == destination
        if(n == 1){
            return 1;
        }
        
        // {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        dist[0][0] = 0;
        
        // 8 directions
        int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            
            for(int i = 0; i < 8; i++){
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n 
                    && grid[nRow][nCol] == 0 && (dist[nRow][nCol] > dis+1)){
                    
                    dist[nRow][nCol] = dis+1;
                    
                    // destination reached
                    if(nRow == n-1 && nCol == n-1){
                        return dist[nRow][nCol] + 1;
                    }
                    
                    q.push({dis+1, {nRow, nCol}});
                }
            }
        }
        
        return -1;
    }
};
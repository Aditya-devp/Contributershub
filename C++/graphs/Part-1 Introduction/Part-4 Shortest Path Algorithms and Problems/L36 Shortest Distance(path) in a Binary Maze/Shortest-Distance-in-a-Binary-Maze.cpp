//* https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
//* https://youtu.be/U5Mw4eyUmw4

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                    pair<int, int> destination) {
        // code here
        
        // Edge Case-> when source == destination
        if(source.first == destination.first && source.second == destination.second){
            return 0;
        }
        
        // {distance, {row, col}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {source.first, source.second}});
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[source.first][source.second] = 0;
        
        // 4 directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            
            for(int i = 0; i < 4; i++){
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                    && grid[nRow][nCol] == 1 && (dist[nRow][nCol] > dis+1)){
                    
                    dist[nRow][nCol] = dis+1;
                    
                    if(nRow == destination.first && nCol == destination.second){
                        return dist[nRow][nCol];
                    }
                    
                    q.push({dis+1, {nRow, nCol}});
                }
            }
        }
        
        return -1;
    }
};
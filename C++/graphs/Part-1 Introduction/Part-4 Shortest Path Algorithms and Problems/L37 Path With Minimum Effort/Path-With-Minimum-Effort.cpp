//* https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort
//* Using Dijkstra's -> https://youtu.be/0ytpZyiZFhA

class Solution {
public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        
        
        int n = heights.size();
        int m = heights[0].size();

        // {effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        
        // 4 directions
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int diff = node.first;
            int row = node.second.first;
            int col = node.second.second;

            // destination reached with minimum value of maximum effort
            if(row == n-1 && col == m-1){
                return diff;
            }
            
            for(int i = 0; i < 4; i++){
                int nRow = row + dr[i];
                int nCol = col + dc[i];
                
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    
                    int newEffort = max(abs(heights[row][col] - heights[nRow][nCol]), diff);

                    if(newEffort < dist[nRow][nCol]){
                        dist[nRow][nCol] = newEffort;
                        pq.push({newEffort, {nRow, nCol}});
                    }
                }
            }
        }
        
        return 0; // reachable
    }
};
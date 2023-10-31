//* https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall2042
//* https://youtu.be/YbY8cVwWAvw

class Solution {
public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
        
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j){
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }
	}
};
//* Using Djikstra's Algorithm
//* https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end
//* https://youtu.be/_BvEJ3VIDWw

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        const int mod = 1e5;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        queue<pair<int,int>> q;
        // {steps, node}
        q.push({0, start});
        
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        
        
        while(!q.empty()){
            auto temp = q.front(); q.pop();
            int steps = temp.first;
            int node = temp.second;
            
            for(auto it : arr){
                int adjNode = (node * it) % mod;
                
                if(steps + 1 < dist[adjNode]){
                    
                    dist[adjNode] = steps + 1;
                    
                    if(adjNode == end){
                        return steps + 1;
                    }
                    
                    q.push({steps+1, adjNode});
                }
                
            }
        }
        
        return -1;
    }
};
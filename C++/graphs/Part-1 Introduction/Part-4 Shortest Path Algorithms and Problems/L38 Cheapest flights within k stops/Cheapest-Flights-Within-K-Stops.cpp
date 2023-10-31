//* https://practice.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=cheapest-flights-within-k-stops
//* https://youtu.be/9XybHVqTHcQ

class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        
        
        // creating adjacency list
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // pushing start point
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int stopsTaken = node.first;
            int currNode = node.second.first;
            int currCost = node.second.second;

            // can't go further if max limit of stops reaached
            if(stopsTaken > K){
                continue;
            }

            for(auto it : adj[currNode]){
                int adjNode = it.first;
                int cost = it.second;

                if(dist[adjNode] > currCost + cost && stopsTaken <= K){
                    dist[adjNode] = currCost + cost;
                    q.push({stopsTaken + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        // unreachable
        if(dist[dst] == 1e9){
            return -1;
        }

        return dist[dst];
    }
};
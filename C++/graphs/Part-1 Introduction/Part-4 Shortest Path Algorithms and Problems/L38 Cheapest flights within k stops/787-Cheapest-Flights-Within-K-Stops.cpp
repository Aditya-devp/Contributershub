//* https://leetcode.com/problems/cheapest-flights-within-k-stops/
//* https://youtu.be/9XybHVqTHcQ

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
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
            if(stopsTaken > k){
                continue;
            }

            for(auto it : adj[currNode]){
                int adjNode = it.first;
                int cost = it.second;

                if(dist[adjNode] > currCost + cost && stopsTaken <= k){
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
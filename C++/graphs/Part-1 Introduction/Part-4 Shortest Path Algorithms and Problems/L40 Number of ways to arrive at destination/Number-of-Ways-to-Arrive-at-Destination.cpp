//* https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
//* https://youtu.be/_-0mx0SmYxA
//* change all ints to long long

#define ll long long

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        // create adjacency list
        vector<pair<ll, ll>> adj[n];
        for(auto it : roads){
            // undirected graph
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<ll> ways(n, 0);
        ways[0] = 1;
        // stores min distances
        vector<ll> dist(n, LONG_MAX);
        dist[0] = 0;

        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        // {dist, node}
        pq.push({0, 0});

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ll dis = temp.first;
            ll node = temp.second;

            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll wt = it.second;

                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt; 
                    pq.push({dis+wt, adjNode});
                    ways[adjNode] = ways[node]; // important
                }
                else if(dis + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // important
                }
            }
        }

        return ways[n-1] % mod;
    }
};
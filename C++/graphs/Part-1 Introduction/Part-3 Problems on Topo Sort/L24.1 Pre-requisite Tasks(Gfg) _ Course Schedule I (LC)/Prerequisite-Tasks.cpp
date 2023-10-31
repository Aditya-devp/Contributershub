//* https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks
//* https://youtu.be/WAOfKpxYHR8

class Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    // Code here
        
        vector<int> adj[N];
        
        // Creating Adjacency List
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
        }
        
        return using_kahnAlgo(N, adj);
	}
	
	bool using_kahnAlgo(int V, vector<int> adj[]){
        
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++){
            for(int adjNode : adj[i]){
                indegree[adjNode]++; // calculating indegree of every node
            }
        }

        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i); // pushing starting sources
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();

            topo.push_back(node);

            for(int adjNode : adj[node]){
                indegree[adjNode]--;

                // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        if(topo.size() == V){
            return true;
        }

        return false;
    }
};
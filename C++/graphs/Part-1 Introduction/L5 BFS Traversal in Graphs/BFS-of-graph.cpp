//* https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph
//* https://youtu.be/-tgVpUgsQ5k

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> ans;
        vector<int> vis(V, 0);
        
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()){
            int curr_node = q.front();
            q.pop();
            ans.push_back(curr_node);
            
            // adding neighbours of node
            for(auto& i : adj[curr_node]){
                if(!vis[i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        
        return ans;
    }
};
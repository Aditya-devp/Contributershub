//* https://leetcode.com/problems/course-schedule/
//* https://youtu.be/WAOfKpxYHR8

class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
        vector<int> adj[numCourses];

        // Creating Adjacency List
        for (auto it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        return using_kahnAlgo(numCourses, adj);
    }

    bool using_kahnAlgo(int V, vector<int> adj[]){

        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++){
            for (int adjNode : adj[i]){
                indegree[adjNode]++; // calculating indegree of every node
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++){
            if (indegree[i] == 0){
                q.push(i); // pushing starting sources
            }
        }

        vector<int> topo;
        while (!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int adjNode : adj[node]){
                indegree[adjNode]--;

                // new start points
                if (indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        if (topo.size() == V){
            return true;
        }

        return false;
    }
};
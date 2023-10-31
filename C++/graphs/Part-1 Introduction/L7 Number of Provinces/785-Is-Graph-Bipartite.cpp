//* https://leetcode.com/problems/is-graph-bipartite/
//* Using BFS-> https://youtu.be/-vu34sct1g8
//* Using DFS-> https://youtu.be/KG5YFfR0j8A

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // all are uncolored

        //* Checking for connected components
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                
                //* Method-1 -> BFS
                if(bfs(i, graph, color, n) == false){
                    return false;
                }

                //* Method-2 -> DFS
                // if(dfs(i, 0, graph, color) == false){
                //     return false;
                // }
            }
        }

        return true;
    }

    bool bfs(int src, vector<vector<int>>& graph, vector<int>& color, int n){

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int adjnode : graph[node]){

                // not yet colored
                if(color[adjnode] == -1){
                    color[adjnode] = !color[node];
                    q.push(adjnode);
                }
                else if(color[adjnode] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }

    bool dfs(int node, int col, vector<vector<int>>& graph, vector<int>& color){
        color[node] = col;
        
        for(int adjnode : graph[node]){
            // not yet colored
            if(color[adjnode] == -1){
                if(dfs(adjnode, !col, graph, color) == false){
                    return false;
                }
            }
            else if(color[adjnode] == color[node]){
                return false;
            }
        }
        return true;
    }
};
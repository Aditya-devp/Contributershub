//* https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
//* https://youtu.be/U3N_je7tWAs

class Solution{
public:
    string findOrder(string dict[], int N, int K) {
        //code here
        
        vector<int> adj[K];
        
        // create graph
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(), s2.size());
            
            for(int i = 0; i < len; i++){
                if(s1[i] != s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        
        vector<int> sequence = using_bfs_kahnsAlgo(K, adj);
        
        string ans = "";
        for(auto it : sequence){
            ans += (it+'a');
        }
        
        return ans;
    }
    
    //* BFS
    vector<int> using_bfs_kahnsAlgo(int V, vector<int> adj[]){
        
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
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            ans.push_back(node);
            
            for(int adjNode : adj[node]){
                indegree[adjNode]--;
                
                // new start points
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }

        return ans;
    }
};
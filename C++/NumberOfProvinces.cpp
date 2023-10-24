// LeetCode Problem Link :- https://leetcode.com/problems/number-of-provinces/
// Author :- Anup Jeejo

class Solution {
public:

    void dfs(int node, vector<int> adjLs[], vector<int> &vis)
    {
        vis[node] = 1;

        for(auto adjNode : adjLs[node])
        {
            if(!vis[adjNode])
                dfs(adjNode, adjLs, vis);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];
        vector<int> vis(n, 0);
        int cnt=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};
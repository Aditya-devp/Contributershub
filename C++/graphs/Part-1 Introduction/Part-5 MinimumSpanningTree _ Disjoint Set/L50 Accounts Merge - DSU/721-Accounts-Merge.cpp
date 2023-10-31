//* https://leetcode.com/problems/accounts-merge/
//* Using DSU-> https://youtu.be/FMwpt_aQOGw

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        
        DisjointSet ds(n);

        sort(accounts.begin(), accounts.end());

        // {email, index}
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];

                // not yet mapped to any index
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i; // added to node i
                }
                else{
                    // already present in some other node, so attach this whole node i to mapMailNode[mail] node
                    ds.unionBySize(i, mapMailNode[mail]); // join nodes, as they belong to same person
                }
            }
        }


        vector<string> mergeMail[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second); // ultimate parent
            mergeMail[node].push_back(mail); // 
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            if(mergeMail[i].size() == 0){
                continue;
            }

            sort(mergeMail[i].begin(), mergeMail[i].end());

            vector<string> temp{accounts[i][0]}; // push name of person
            //pushing mails
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    //* <------------------------- Disjoint Set Util Starts ------------------------->

    class DisjointSet{
    public:
        vector<int> parent, rank, size;

        // constructor
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1);

            for(int i = 0; i <= n; ++i){
                parent[i] = i;
            }
        }

        // find ultimate parent
        int findUPar(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUPar(parent[node]); // does path compression as well
        }

        // union by rank
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u); // calculate ultimate parent of u
            int ulp_v = findUPar(v); // calculate ultimate parent of v

            // if both have same ULP, means both are in same set
            if(ulp_u == ulp_v){
                return;
            }

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        // union by size
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u); // calculate ultimate parent of u
            int ulp_v = findUPar(v); // calculate ultimate parent of v

            // if both have same ULP, means both are in same set
            if(ulp_u == ulp_v){
                return;
            }

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    //* <------------------------- Disjoint Set Util Ends ------------------------->

};
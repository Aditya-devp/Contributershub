#include <bits/stdc++.h>
using namespace std;

//* <------------------------- Disjoint Set Util Starts ------------------------->

class DisjointSet{
public:
    vector<int> rank, parent;

    // constructor
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

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
};

//* <------------------------- Disjoint Set Util Ends ------------------------->


int main() {

    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
}
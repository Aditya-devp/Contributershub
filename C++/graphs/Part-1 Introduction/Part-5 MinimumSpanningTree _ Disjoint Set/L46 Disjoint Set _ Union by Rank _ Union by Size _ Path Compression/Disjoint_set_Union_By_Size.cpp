#include <bits/stdc++.h>
using namespace std;

//* <------------------------- Disjoint Set Util Starts ------------------------->

class DisjointSet{
public:
    vector<int> size, parent;

    // constructor
    DisjointSet(int n){
        size.resize(n + 1);
        parent.resize(n + 1);

        for(int i = 0; i <= n; ++i){
            parent[i] = i;
            size[i] = 1;
        }
    }

    // find ultimate parent
    int findUPar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findUPar(parent[node]); // does path compression as well
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


int main() {

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    
    return 0;
}
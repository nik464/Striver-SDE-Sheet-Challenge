#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
vector<int> bellman_ford(int V, vector<vector<int>>& edges, int s) {
        // Code here
        // for storing dist from source to other vertices
        vector<int> dist(V, 1e8);
        // dist of source from source is zero
        dist[s]=0;
        for(int i=0; i<V-1; i++){
            for(auto e : edges){
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                // relax operation
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        // to detect negative cycle
        bool ncycle=false;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            if(dist[u]+wt<dist[v]){
                // dist[v]=dist[u]+wt;
                ncycle=true;
                break;
            }
        }
        if(ncycle) return {-1};
        return dist;
    }
    
};



#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        
        vis[0]=1;
        queue<int>q;
        q.push(0);
        vector<int>bfs;
        
        
        while(!q.empty())
        {
            int t= q.front();
            q.pop();
            bfs.push_back(t);
            
            for(auto it: adj[t])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
                
            }
        }
        return bfs;
    }
};
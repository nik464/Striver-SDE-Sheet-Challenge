#includ<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>ans;
        vector<int>dis(V,INT_MAX);
        
        queue<pair<int,int>>q;
        q.push({S,0});
        dis[S]=0;
        while(!q.empty()){
            int curr=q.front().first,weight=q.front().second;
            q.pop();
            for(auto it:adj[curr]){
                
            int v=it[0],w=it[1];
            if(w+weight<dis[v])
            {
                q.push({v,w+weight});
                dis[v]=w+weight;
                
            }
         }
        }
        for(int i=0;i<V;i++){
            ans.push_back(dis[i]);
        }
        return ans;
    }
};


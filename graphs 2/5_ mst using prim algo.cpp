#include<bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        using pairInt = pair<int, int>;
        int mstRes = 0;
        priority_queue<pairInt, vector<pairInt>, greater<pairInt>> pq;
        pq.push({0, 0});
        vector<bool> visited(V, false);
        while(!pq.empty()) {
            const auto curr = pq.top();
            pq.pop();
            const int wt = curr.first;
            const int u = curr.second;
            if(visited[u]) continue;
            visited[u] = true;
            mstRes += wt;
            for(const auto v : adj[u])
                if(!visited[v[0]])
                    pq.push({v[1], v[0]});
        }
        
        return mstRes;
    }
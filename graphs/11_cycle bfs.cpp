#include<bits/stdc++.h>
using namespace std;
bool cycle( int start, vector<int> & vis, vector<int>adj[] )
{
    vis[start]=1;
    queue<pair<int, int>>q;
    q.push({start, -1});

    while(!q.empty())
    {
        int node= q.front().first;
        int parent=q.front().second;

        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(cycle(it, vis, adj))
                {
                    vis[it]=1;
                    q.push({it, node});
                }
            }

            else if (it!=parent)
            return true;
        }

    }

    return false;
}
bool iscycle (int V, vector<int>adj[])
{
  
    int vis[V]={0};

    for(int i=0;i<V;i++)   //connected commponents
    {
        if(!vis[i])
        {
            if(cycle(i, vis, adj))
            return true;
        }

    }

    return false;
}
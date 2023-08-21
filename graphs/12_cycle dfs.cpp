#include<bits/stdc++.h>
using namespace std;

bool cycle(int i , int parent, int vis[], vector<int>adj[])
{
    vis[i]=1;

    for(auto it:adj[i])
    {
        if(!vis[it])
        {
          if(dfs(it, i, vis, adj)==true)
          return true;
        }
        
        else  if(it !=parent)
        return true;
    }

    return false;

}

bool isycle(int V, vector<int>adj[])
{
    int vis[V]={0};

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(cycle(i, -1, vis, adj))
            return true;
        }
    }

    return false;
}
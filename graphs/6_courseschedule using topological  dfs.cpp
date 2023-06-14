#include<bits/stdc++.h>
using namespace std;


//detect cycle using dfs
class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        int N=n;
         vector<int>adj[N];
	     int indegree[N]={0};
	     
	     queue<int>q;
	     
	     vector<int>ans;
	     
	     for(auto i: prerequisites)
	     {
	         adj[i[1]].push_back(i[0]);
	         
	     }
	     
	     for(int i=0;i<N;i++)
	     {
	         for(auto it: adj[i])
	         indegree[it]++;
	     }
	     
	     
	     for(int i=0;i<N;i++)
	     {
	         if(indegree[i]==0)
	         q.push(i);
	     }
	     
	     
	     while(!q.empty())
	     {
	         int t = q.front();
	         q.pop();
	         
	         ans.push_back(t);
	         
	         
	         for(auto it: adj[t])
	         {
	             indegree[it]--;
	             if(indegree[it]==0)
	             q.push(it);
	         }
	     }
	     
	     if(ans.size()==N)
	     return ans;
	     
	     return {};
    }
};






/*
detect cycle using dfs in undirected

bool checkcyle(int node , int parent, int vis[], vector<int>adj[] )
{
    vis[node]=1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(checkcycle(it, node, vis, adj))
            return true;

            else if(it!=parent)
            return true;
        }
    }
}

bool iscycle( int V, vector<int>adj[])
{
    int vis[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(checkcycle(i,-1,  vis, adj))  //-1 is for parent
            return true;
        }
    
    }

    return false;

}


*/ 


/*
detect cycle using dfs in directed

bool checkcyle(int node , int dvis[], int vis[], vector<int>adj[] )
{
    vis[node]=1;
    dvis[node]=1;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(checkcycle(it, dvis, vis, adj))
            return true;

            else if(dvis[it])
            return true;
        }
    }

    return false;
}

bool iscycle( int V, vector<int>adj[])
{
    int vis[V]={0};
    int dvis[V]={0};

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(checkcycle(i, dvis,  vis, adj))  //-1 is for parent
            return true;
        }
    
    }

    return false;

}


*/ 

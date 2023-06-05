#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs( int i, vector<int>adj[], int  vis[], stack<int> &s)
	{
	    vis[i]=1;
	    
	    
	    for(auto it: adj[i])
	    {
	        if(!vis[it])
	        dfs(it, adj, vis, s);
	        
	    }
	    
	    s.push(i);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    
	    vector<int>l;
	    stack<int>s;
	    
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i, adj, vis, s);
	        }
	    }
	    
	    
	    while(!s.empty())
	    {
	        l.push_back(s.top());
	        s.pop();
	    }
	  
	  return l;
	}
};
#include<bits/stdc++.h>
using namespace std;

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


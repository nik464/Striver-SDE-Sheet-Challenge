#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<Node*, Node*> &m)
    {
        vector<Node*>solution;
        Node* clone= new Node(node->val);
        m[node]=clone;

        for(auto it:node->neighbors)
        {
            if(m.find(it)!=m.end())
            clone->neighbors.push_back(m[it]);
            else
             {
                 dfs(it,m);
                 clone->neighbors.push_back(m[it]);
             }
            
        }

         
         
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*>m;

        if(node==NULL)
        return NULL;

        if(node->neighbors.size()==0)
        {
            Node* newNode= new Node(node->val);
            return newNode;

        }

        dfs(node, m);

        return m[node];
    }
};
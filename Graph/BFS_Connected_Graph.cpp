
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> BFSHelper(vector<int> adj[],int start,bool visited[]){
        vector<int> vc;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(q.empty()==false){
            int u = q.front();
            q.pop();
            vc.push_back(u);
            for(int v : adj[u]){
                if(visited[v] == false){
                    visited[v] = true;
                    q.push(v);
                }
            }
            
        }
        return vc;
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vc;
        bool visited[V+1];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        vc = BFSHelper(adj,0,visited);
        return vc;
    }
};
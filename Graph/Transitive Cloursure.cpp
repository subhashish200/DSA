class Solution{
public:
    void helper(vector<int> adj[],int i,int row,vector<vector<int>> &res,vector<int> &visited){
        visited[i] = 1;
        res[row][i] = 1;
        for(int j : adj[i]){
            if(visited[j]==0){
                helper(adj,j,row,res,visited);
            }
        }
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j or graph[i][j]==0){
                    continue;
                }else{
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>> res(N,vector<int>(N,0));
        for(int i=0;i<N;i++){
            vector<int> visited(N,0);
            helper(adj,i,i,res,visited);
        }
        return res;
    }
};
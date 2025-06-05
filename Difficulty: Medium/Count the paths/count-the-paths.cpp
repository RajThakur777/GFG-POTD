class Solution {
  public:
  
    int solve(vector<vector<int>> &adj , vector<int> &dp , int node , int &src , int &dest){
        if(node == dest) return 1;
        
        if(dp[node] != -1) return dp[node];
        
        int ans = 0;
        for(auto it : adj[node]) {
            ans += solve(adj , dp , it , src , dest);
        }
        return dp[node] = ans;
    }
  
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<int> dp(V , -1);
        
        return solve(adj , dp , src , src , dest);
    }
};
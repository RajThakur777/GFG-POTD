class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        int N = prerequisites.size();
        
        unordered_map<int , vector<int>> adj;
        
        vector<int> indegree(n , 0);
        
        for(int i=0; i<N; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        
        while(!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();
            
            for(auto it : adj[node]) {
                indegree[it]--;
                
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return res;
    }
};
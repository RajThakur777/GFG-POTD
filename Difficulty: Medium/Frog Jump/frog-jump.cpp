class Solution {
  public:
    virtual int minCostUtility(int i, int &n, vector<int> &a, vector<int> &dp){
      if(i == (n-1))
        return 0;
      if(dp[i] != -1)
        return dp[i];
      
      int step1 = abs(a[i+1] - a[i]) + minCostUtility(i+1, n, a, dp);
      int step2 = INT_MAX;
      if((i+2) < n)
        step2 = abs(a[i+2] - a[i]) + minCostUtility(i+2, n, a, dp);
      
      return dp[i] = min(step1, step2);
            
    }
  
    virtual int minCost(vector<int> &height) {
      int n = height.size();
      vector<int> dp(n+1, -1);
      
      return minCostUtility(0, n, height, dp);    
        
    }
};
class Solution {
  public:
    virtual int util(int i, vector<int> &dp){
      if((i==1) || (i==2))
        return i;
      if(dp[i] != -1)
        return dp[i];
      return dp[i] = util(i-1, dp) + util(i-2, dp);    
    }
  
    virtual int numberOfWays(int n) {
      vector<int> dp(n+1, -1);
      return util(n, dp);
    }
};
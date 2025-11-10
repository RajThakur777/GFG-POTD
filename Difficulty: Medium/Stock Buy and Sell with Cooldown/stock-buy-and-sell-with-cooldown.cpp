class Solution {
  public:
    int n;
    
    int dp[100001][2];
    
    int solve(int idx , vector<int> &arr , int buy) {
        if(idx >= arr.size()) {
            return 0;
        }
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        int profit = INT_MIN;
        
        if(buy == 0) {
            profit = max(-arr[idx] + solve(idx+1 , arr , 1) , solve(idx+1 , arr , 0));
        }
        else {
            profit = max(arr[idx] + solve(idx+2 , arr , 0) , solve(idx+1 , arr , 1));
        }
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& arr) {
        // code here
        n = arr.size();
        
        memset(dp , -1 , sizeof(dp));
        
        return solve(0 , arr , 0);
    }
};
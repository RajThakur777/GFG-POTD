class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int sum = 0;
        int ans = INT_MIN;
        
        int i = 0;
        for(int j=0; j<n; j++) {
            sum += arr[j];
            
            while((j - i + 1) > k) {
                sum -= arr[i];
                i++;
            }
            
            if((j - i + 1) == k) {
                ans = max(ans , sum);
            }
        }
        return ans;
    }
};
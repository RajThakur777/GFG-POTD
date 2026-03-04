class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        int xor_val = 0;
        
        int i = 0;
        for(int j=0; j<n; j++) {
            xor_val ^= arr[j];
            while((j - i + 1) > k) {
                xor_val ^= arr[i];
                i++;
            }
            
            if((j - i + 1) == k) {
                ans = max(ans , xor_val);
            }
        }
        return ans;
    }
};
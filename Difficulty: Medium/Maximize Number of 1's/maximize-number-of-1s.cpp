class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int ans = INT_MIN;
        
        int i = 0;
        int zero = 0;
        for(int j=0; j<n; j++) {
            if(arr[j] == 0) {
                zero++;
            }
            
            while(zero > k) {
                if(arr[i] == 0) {
                    zero--;
                }
                i++;
            }
            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};

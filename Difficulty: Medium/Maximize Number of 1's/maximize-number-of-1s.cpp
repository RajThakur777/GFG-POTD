class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        
        int i = 0;
        int cnt = 0;
        for(int j=0; j<n; j++) {
            cnt += (arr[j] == 0);
            
            while(cnt > k) {
                cnt -= (arr[i] == 0);
                i++;
            }
            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};

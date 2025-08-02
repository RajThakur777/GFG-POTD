class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        
        vector<int> res(n);
        
        for(int i=0; i<n; i++) {
            if(arr[i] > k) {
                res[i] = 1;
            }
            else {
                res[i] = -1;
            }
        }
        
        int sum = 0;
        int len = 0;
        
        unordered_map<int , int> mpp;
        
        for(int i=0; i<n; i++) {
            sum += res[i];
            
            if(sum > 0) {
                len = max(len , i+1);
            }
            else {
                   if(mpp.find(sum - 1) != mpp.end()) {
                len = max(len , i - mpp[sum - 1]);
            }
            }
            
            if(mpp.find(sum) == mpp.end()) {
                mpp[sum] = i;
            }
        }
        return len;
    }
};
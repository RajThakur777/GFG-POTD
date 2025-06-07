class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        
        int ans = INT_MIN;
        
        vector<int> c(n);
        
        for(int i=0; i<n; i++){
            c[i] = (a1[i] - a2[i]);
        }
        
        map<int , int> mpp;
        mpp[0] = -1;
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += c[i];
            
            if(mpp.find(sum) != mpp.end()) {
                ans = max(ans , i - mpp[sum]);
            }
            else if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
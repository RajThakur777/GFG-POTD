class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        vector<int> res(n);
        for(int i=0; i<n; i++) {
            if(arr[i] % 2 == 0) {
                res[i] = 0;
            }
            else {
                res[i] = 1;
            }
        }
        
        unordered_map<int , int> mpp;
        mpp[0] = 1;
        
        int cnt = 0;
        
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += res[i];
            
            if(mpp.find(sum - k) != mpp.end()) {
                cnt += mpp[sum - k];
            }
            mpp[sum]++;
        }
        return cnt;
    }
};
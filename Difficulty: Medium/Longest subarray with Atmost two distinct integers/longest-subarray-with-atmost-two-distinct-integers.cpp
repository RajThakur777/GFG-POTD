class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        map<int , int> mpp;
        
        int ans = INT_MIN;
        
        int i = 0;
        for(int j=0; j<n; j++) {
            mpp[arr[j]]++;
            
            while(mpp.size() > 2) {
                mpp[arr[i]]--;
                
                if(mpp[arr[i]] == 0) {
                    mpp.erase(arr[i]);
                }
                i++;
            }
            ans = max(ans , (j - i + 1));
        }
        return ans;
    }
};
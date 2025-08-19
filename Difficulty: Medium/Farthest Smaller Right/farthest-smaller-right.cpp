class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> ans(n);
        
        vector<int> suffix(n);
        suffix[n-1] = arr[n-1];
        
        for(int i=n-2; i>=0; i--) {
            suffix[i] = min(suffix[i+1] , arr[i]);
        }
        
        for(int i=0; i<n; i++) {
            int l = i+1; 
            int h = n-1;
            
            int res = -1;
            
            while(l <= h) {
                int mid = (l + h) / 2;
                
                if(suffix[mid] < arr[i]) {
                    res = mid;
                    l = mid + 1;
                }
                else {
                    h = mid - 1;
                }
            }
            ans[i] = res;
        }
        return ans;
    }
};
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int ans = 0;
        
        int i = 0;
        int j = n-1;
        
        while(i < j) {
            ans = max(ans , (j-i) * min(arr[i] , arr[j]));
            if(arr[i] < arr[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};
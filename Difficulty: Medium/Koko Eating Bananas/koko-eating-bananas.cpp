class Solution {
  public:
  
    bool check(int mid , vector<int> &arr , int k) {
        int cnt = 0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= mid) {
                cnt++;
            }
            else {
                cnt += ((arr[i] + mid - 1) / mid);
            }
        }
        return (cnt <= k);
    }
  
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size();
        
        int ans = 0;
        
        int low = 1;
        int high = *max_element(arr.begin() , arr.end());
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(check(mid , arr , k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
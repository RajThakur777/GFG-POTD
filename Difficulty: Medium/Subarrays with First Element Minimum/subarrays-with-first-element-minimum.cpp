class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        deque<int> dq;
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            while(!dq.empty() && dq.back() > arr[i]) {
                dq.pop_back();
            }
            
            dq.push_back((arr[i]));
            ans += dq.size();
        }
        return ans;
    }
};
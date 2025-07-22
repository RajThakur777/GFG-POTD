class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        set<int> st;
        for(int i=0; i<n; i++) {
            if(arr[i] > 0) {
                st.insert(arr[i]);
            }
        }
        
        int ans = 0;
        for(int i=1; i<=1e6; i++) {
            if(st.find(i) == st.end()) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> ans(n);
        
        map<int , int> mpp;
        for(int i=0; i<n; i++) {
            mpp[arr[i]]++;
        }
        stack<int> st;
        
        for(int i=n-1; i>=0; i--) {
            while(st.size() > 0 && mpp[st.top()] <= mpp[arr[i]]) {
                st.pop();
            }
            
            if(st.size() == 0) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans; 
    }
};

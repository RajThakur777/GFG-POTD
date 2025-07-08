class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> res(2*n);
        for(int i=0; i<n; i++) {
            res[i] = arr[i];
        }
        
        int j = 0;
        for(int i=n; i<2*n; i++) {
            res[i] = arr[j++]; 
        }
        
        vector<int> ans(n);
        
        stack<int> st;
        
        for(int i=2*n-1; i>=0; i--) {
            while(st.size() > 0 && st.top() <= res[i%n]) {
                st.pop();
            }
            if(st.size() == 0) {
                ans[i%n] = -1;
            }
            else {
                ans[i%n] = st.top();
            }
            st.push(res[i%n]);
        }
        return ans;
    }
};
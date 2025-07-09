class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=(int)arr.size();
        stack<int>st;
        
        vector<int>nS(n,-1);
        vector<int>pS(n,-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]<=arr[st.top()])
            st.pop();
            
            if(!st.empty())
            nS[i]=st.top();
            else 
            nS[i]=n;
            st.push(i);
        }
        while(!st.empty())
        st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<arr[st.top()])
            st.pop();
            
            if(!st.empty())
            pS[i]=st.top();

            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int l=pS[i];
          
            int r=nS[i];
            
            // cout<<l<<" "<<r<<endl;
            int len=(i-l)*(r-i);
            ans+=len*arr[i];
        }
        return ans;
    }
};
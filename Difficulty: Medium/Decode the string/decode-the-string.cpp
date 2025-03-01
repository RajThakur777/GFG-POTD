//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
           int n = s.size();

        string ans = "";

        stack<char> st;

        for(int i=0; i<n; i++){
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else {
                string curr = "";

                while(!st.empty() && st.top() != '['){
                    curr = st.top() + curr;
                    st.pop();
                }

                st.pop();

                //extract number:
                string num = "";

                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }

                int k = stoi(num);

                while(k--){
                    for(int j=0; j<curr.size(); j++){
                        st.push(curr[j]);
                    }
                }
                curr = "";
                num = "";
            }
        }
        while(!st.empty()){
            ans =  st.top() + ans;
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
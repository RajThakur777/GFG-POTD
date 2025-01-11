//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        
        int maxi = 0;
        int cnt = 0;
        
        set<char> st;
        
        for(int i=0; i<n; i++){
            while(st.find(s[i]) != st.end()){
                st.erase(s[cnt]);
                cnt++;
            }
            
            st.insert(s[i]);
            
            maxi = max(maxi , i - cnt + 1);
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
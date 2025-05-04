//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size();
        
        int len = INT_MAX;
        
        set<char> st;
        for(int i=0; i<str.size(); i++){
            st.insert(str[i]);
        }
        
        int sz = st.size();
        
        map<char , int> mpp;
        int i = 0;
        for(int j=0; j<n; j++){
            mpp[str[j]]++;
            
            while(mpp.size() >= sz){
                len = min(len , j - i + 1);
                
                mpp[str[i]]--;
                
                if(mpp[str[i]] == 0){
                    mpp.erase(str[i]);
                }
                
                i++;
            }
        }
        return len;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string> uniquePerms;
        
        sort(s.begin(), s.end()); 

        do {
         uniquePerms.insert(s);  
        } while (next_permutation(s.begin(), s.end())); 


    vector<string> result(uniquePerms.begin(), uniquePerms.end());
    return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
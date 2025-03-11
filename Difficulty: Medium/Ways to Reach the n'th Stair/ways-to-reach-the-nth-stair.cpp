//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int helper(vector<int> &dp , int i){
        if(i == 1) return 1;
        if(i == 2) return 2;
        
        if(dp[i] != -1) return dp[i];
        
        return dp[i] = helper(dp , i-1) + helper(dp , i-2);
    }
  
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1 , -1);
        
        int i = n;
        
        int ans = helper(dp , i);
        
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
  
    int helper(vector<int> &cost , int idx , vector<int> &dp){
        if(idx >= cost.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int one = cost[idx] + helper(cost , idx+1 , dp);
        
        int two = cost[idx] + helper(cost , idx+2 , dp);
        
        return dp[idx] = min(one , two);
    }
  
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
        int n = cost.size();
        
        vector<int> dp(n+1 , -1);
        
        int ans = min(helper(cost , 0 , dp) , helper(cost , 1 , dp));
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
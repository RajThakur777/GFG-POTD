//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  
    // Helper function for memoization
    int helper(vector<int>& coins, int sum, int idx, vector<vector<int>>& dp) {
        // Base cases
        if (sum == 0) {
            return 1;  // We found a valid combination to make the sum
        }
        if (idx >= coins.size() || sum < 0) {
            return 0;  // No valid combination found (either out of coins or sum becomes negative)
        }

        // If already computed, return the stored result
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        // Two choices: pick the coin or skip it
        int pick = helper(coins, sum - coins[idx], idx, dp);  // Pick the current coin
        int not_pick = helper(coins, sum, idx + 1, dp);        // Skip the current coin
        
        // Store and return the result for the current state
        dp[idx][sum] = pick + not_pick;
        return dp[idx][sum];
    }
  
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        
        // Start the helper function from the first coin and given sum
        return helper(coins, sum, 0, dp);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
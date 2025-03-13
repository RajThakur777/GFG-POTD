//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int helper(int W , int idx , vector<int> &val , vector<int> &wt , vector<vector<int>> &dp){
        if(idx >= wt.size()){
            return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        //pick
        int pick = 0;
        if(wt[idx] <= W){
            pick = val[idx] + helper(W - wt[idx] , idx + 1 , val , wt , dp);
        }
        //not-pick
        int not_pick = helper(W , idx + 1 , val , wt , dp);
        
        return dp[idx][W] = max(pick , not_pick);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<vector<int>> dp(n+1 , vector<int>(W+1));
        for(int i=0; i<n; i++){
            for(int j=0; j<W+1; j++){
                dp[i][j] = -1;
            }
        }
        int ans = helper(W , 0 , val , wt , dp);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
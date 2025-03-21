//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  
    int helper(int idx , vector<int>& arr , vector<int>& dp){
        if(idx >= arr.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        //pick
        int pick = arr[idx] + helper(idx+2 , arr , dp);
        
        //not_pick
        int not_pick = helper(idx+1 , arr , dp);
        
        return dp[idx] = max(pick , not_pick);
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector<int> dp(n+1 , -1);
        
        int ans = helper(0 , arr , dp);
        
        return ans;
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int helper(int i,int endIndex,vector<int>& arr,vector<int>&dp){
        if(i>=endIndex){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int include=arr[i]+helper(i+2,endIndex,arr,dp);
        int exclude=helper(i+1,endIndex,arr,dp);
        
        return dp[i]=max(include,exclude);
    }

    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        vector<int>dp1(n,-1);
        int case1 = helper(0,n-1,arr,dp1);
        vector<int>dp2(n,-1);
        int case2=helper(1,n,arr,dp2);
        
        return max(case1,case2);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
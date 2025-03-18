//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool fun(int i,int sum, vector<int> &arr, vector<vector<int>> &dp){
        if(sum==0)
            return true;
        if(i<0)
            return false;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        int t = 0;
        int nt = fun(i-1, sum, arr, dp);
        
        if(arr[i]<=sum)
            t = fun(i-1, sum-arr[i], arr, dp);
        
        return dp[i][sum] = t || nt;
        
    }
  
    bool isSumPresent(vector<int> &arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return fun(n-1, sum, arr, dp);
        
    }
    
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int n = arr.size();
        int sum = 0;
        for(auto z : arr){
            sum += z;
        }
        
        if(sum&1)
            return false;
          
        return isSumPresent(arr, sum/2);
           
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
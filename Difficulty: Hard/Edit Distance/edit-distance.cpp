//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int func(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.size()){
            return 0;
        }
        if(i==s1.size()){
            return s2.size()-j;
        }
        if(j==s2.size()){
            return s1.size()-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=func(s1,s2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=min(1+func(s1,s2,i+1,j+1,dp),min(1+func(s1,s2,i,j+1,dp),1+func(s1,s2,i+1,j,dp)));
        }
    }
    int editDistance(string& s1, string& s2) {
        int n=s1.size(),m=s2.size();
        if(s1==s2)return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(s1,s2,0,0,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        map<int , int> mpp;
        for(int i=0; i<n-1; i++){
            int diff = arr[i+1] - arr[i];
            mpp[diff]++;
        }
        
        int maxi = INT_MIN;
        int diff = 0;
        for(auto it : mpp){
            maxi = max(maxi , it.second);
        }
        
        int res = -1;
        for(auto it: mpp){
            if(it.second == 1){
                res = it.first;
            }
        }
        
        if(res == -1){
            int val = arr[1] - arr[0];
            return arr[n-1] + val;
        }
        
        for(auto it : mpp){
            if(it.second == maxi){
                diff = it.first;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if((arr[i+1] - arr[i]) == res){
                ans = (arr[i] + (res - diff));
            }
        }
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
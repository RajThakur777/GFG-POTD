//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int prefix[n];
        int suffix[n];
        
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1] , arr[i]);
        }
        
        for(int i=n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1] , arr[i]);
        }
        
        int val = 0;
        for(int i=0; i<n; i++){
            val += min(prefix[i] , suffix[i]) - arr[i];
        }
        return val;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
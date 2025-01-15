//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        unordered_map<int , int> mpp;
        mpp[0] = -1;
        
        int maxi = 0;
        
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(mpp.find(sum - k) != mpp.end()){
                maxi = max(maxi , (i - mpp[sum - k]));
            }
            
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
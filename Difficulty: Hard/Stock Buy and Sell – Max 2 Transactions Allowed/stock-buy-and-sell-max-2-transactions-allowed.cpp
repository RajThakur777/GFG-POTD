//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int> &arr) {
        if (arr.size() == 1) {
            return 0;
        }
        int n = arr.size(), ans = 0;
        vector<int>left(n), right(n);
        for (int i=0;i<n;i++) {
            left[i] = (i>0?min(left[i-1], arr[i]):arr[i]);
        }
        for (int i=n-1;i>=0;i--) {
            right[i] = (i<(n-1)?max(right[i+1], arr[i]):arr[i]);
        }
        vector<int>leftProfit(n), rightProfit(n);
        for (int i=0;i<n;i++) {
            leftProfit[i] = (i>0?max(leftProfit[i-1], arr[i]-left[i]):arr[i]-left[i]);
            int j = n-i-1;
            rightProfit[j] = (j<(n-1)?max(rightProfit[j+1], right[j]-arr[j]): right[j]-arr[j]);
        }
        for (int i=0;i<n;i++) {
            ans = max(ans, leftProfit[i]+rightProfit[i]);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
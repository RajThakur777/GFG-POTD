//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        
        vector<int> ans;
        
        int i = 0;
        int sum = 0;
        bool flag = false;
        
        for(int j=0; j<n; j++){
            sum += arr[j];
            
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            
            if(sum == target){
                flag = true;
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        if(flag) return ans;
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
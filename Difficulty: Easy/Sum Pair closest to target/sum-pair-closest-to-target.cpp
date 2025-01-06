//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        sort(arr.begin() , arr.end());
        
        vector<int> ans;
        
        int i = 0;
        int j = n-1;
        
        int l = -1;
        int r = -1;
        
        int minDiff = INT_MAX;
        
        while(i < j){
           int sum = arr[i] + arr[j]; 
           int diff = abs(target - sum);
           
           if(diff < minDiff){
               minDiff = diff;
               l = arr[i];
               r = arr[j];
           }
           
           if(sum < target){
               i++;
           }
           else if(sum > target){
               j--;
           }
           else {
               break;
           }
        }
        
        if(l == -1 && r == -1){
            return {};
        }  
        else {
            return {l , r};
        }
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        // code here.
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(k == 0) break;
            int maxi = i;
            for(int j=i+1; j<n; j++){
                if(s[j] >= s[maxi]){
                    maxi = j;
                }
            }
            
            if(s[maxi] == s[i]){
                continue;
            }
            else {
                swap(s[maxi] , s[i]);
                k--;
            }
        }
        return s;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
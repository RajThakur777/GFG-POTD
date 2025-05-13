//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r > n) return 0;
        if(r == n) return 1;
        if(r == 0) return 1;
        long long ans = 1;
        long long temp = 1;
        if(r < n-r)
            r = n - r;
        for(int i = n; i > r; i--){
            temp *= (n - r - (n - i));
            ans *= i;
            if(ans%temp == 0){
               ans /= temp;
               temp = 1;
            } 
                //cout << temp << " " << ans << " " << i << "\n";
        }
        ans /= temp;
        
            
        return (int)ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
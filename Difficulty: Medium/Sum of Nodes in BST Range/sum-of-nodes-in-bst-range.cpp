/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    int solve(Node* root , int l , int r) {
        if(root == nullptr) return 0;
        
        int ans = 0;
        if(root->data >= l && root->data <= r) {
            ans += root->data;
        }
        
        ans += solve(root->left , l , r);
        ans += solve(root->right , l , r);
        
        return ans;
    }
  
    int nodeSum(Node* root, int l, int r) {
        // code here
        
        return solve(root , l , r);
    }
};

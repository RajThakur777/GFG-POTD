/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int ans = INT_MAX;
    
    void solve(Node* root , Node* k) {
        if(root == nullptr) {
            return;
        }
        
        if(root->data > k->data) {
            ans = min(ans , root->data);
            solve(root->left , k);
        }
        else if(root->data <= k->data) {
            solve(root->right , k);
        }
    }
  
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        solve(root , k);
        
        return (ans == INT_MAX ? -1 : ans);
    }
};
/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int cnt2 = 0;
    int ans2 = 0;
    int n = 0;
    
    
    void rec(Node* root) {
        if(!root) {
            return;
        }

        rec(root->left);

        n++;

        rec(root->right);
    }
    
    void solve2(Node* root , int k) {
        if(!root) {
            return;
        }

        solve2(root->left , k);

        cnt2++;
        
        if(cnt2 == (n - k + 1)) {
            ans2 = root->data;
            return;
        }

        solve2(root->right , k);
    }
    int kthLargest(Node *root, int k) {
        // code here
        rec(root);
        
        solve2(root , k);
        
        return ans2;
    }
};
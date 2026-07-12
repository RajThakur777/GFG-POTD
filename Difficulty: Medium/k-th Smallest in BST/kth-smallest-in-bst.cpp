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
    int cnt1 = 0;
    int ans1 = -1;
    
    void solve1(Node* root , int k) {
        if(!root) {
            return;
        }

        solve1(root->left , k);

        cnt1++;
        
        if(cnt1 == k) {
            ans1 = root->data;
            return;
        }

        solve1(root->right , k);
    }

    int kthSmallest(Node *root, int k) {
        // code here
        solve1(root , k);
        
        return ans1;
    }
};
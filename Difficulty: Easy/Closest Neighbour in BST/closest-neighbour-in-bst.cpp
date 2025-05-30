/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  
    void inorder(vector<int> &ans , Node* root){
        if(root == NULL) return;
        
        inorder(ans , root->left);
        ans.push_back(root->data);
        inorder(ans , root->right);
    }
  
    int findMaxFork(Node* root, int k) {
        // code here
        vector<int> ans;
        inorder(ans , root);
        
        int res = -1;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] <= k){
                res = ans[i];
            }
        }
        return res;
    }
};
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
  
    bool isLeaf(Node* root) {
        if(root == nullptr) {
            return false;
        }
        
        return (root->left == nullptr && root->right == nullptr);
    }
    
    void addLeft(Node* root , vector<int> &ans) {
        if(root == nullptr || isLeaf(root)) {
            return;
        }
        
        ans.push_back(root->data);
        
        if(root->left) {
            addLeft(root->left , ans);
        }
        else if(root->right) {
            addLeft(root->right , ans);
        }
    }
    
    void addLeaves(Node* root , vector<int> &ans) {
        if(!root) {
            return;
        }
        
        if(isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        
        addLeaves(root->left , ans);
        addLeaves(root->right , ans);
    }
    
    void addRight(Node* root , vector<int> &ans) {
        if(root == nullptr || isLeaf(root)) {
            return;
        }
        
        if(root->right) {
            addRight(root->right , ans);
        }
        else if(root->left) {
            addRight(root->left , ans);
        }
        
        ans.push_back(root->data);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == nullptr) {
            return {};
        }
        
        if(isLeaf(root)) {
            return {root->data};
        }
        else {
            ans.push_back(root->data);
        }
        
        addLeft(root->left , ans);
        
        addLeaves(root , ans);
        
        addRight(root->right , ans);
        
        return ans;
    }
};
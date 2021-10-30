//Problem Link - https://leetcode.com/problems/recover-binary-search-tree/

//Solution

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    void traverse(TreeNode* root){
        if(!root)
            return;
        traverse(root->left);
        if(first==NULL && prev->val > root->val)
            first = prev;
        if(prev->val > root->val)
            second = root;
        prev = root;
        traverse(root->right);
    }
};

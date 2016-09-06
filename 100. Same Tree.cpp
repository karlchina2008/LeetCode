/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p and !q) return true;
        if((!p and q) or(p and !q)) return false;
        if(p->val!=q->val) return false;
            return(isSameTree(p->left,q->left) and isSameTree(p->right,q->right));
    }
};

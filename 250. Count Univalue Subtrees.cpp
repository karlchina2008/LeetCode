/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
*/
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        helpcount(root,count);
        return count;
        
    }
    bool helpcount(TreeNode* root,int &count){
        if(!root) return true;
        bool l=helpcount(root->left,count),r=helpcount(root->right,count);
        if((root->left==NULL or root->val==root->left->val) and (root->right==NULL or root->val==root->right->val)){
            if(l and r){
                count++;
                return true;
            };
        }
        return false;
    }
};

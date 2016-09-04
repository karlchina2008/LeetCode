/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        if(p->right){
            TreeNode* temp_1=p->right;
            while(temp_1->left) temp_1=temp_1->left;
            return temp_1;
        }
        else if(p==root) return NULL;
        else{
            TreeNode *parentNode=parent(NULL,root,p);
            return parentNode;
        }
    }
    TreeNode* parent(TreeNode *parentNode,TreeNode* root,TreeNode* p){
        if(root->val>p->val) return parent(root,root->left,p);
        if(root->val<p->val) return parent(parentNode,root->right,p);
        else return parentNode;
    }
};

/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        helpfind(root,res);
        return res;
    }
    void helpfind(TreeNode* root,int& res){
        if(!root or (!root->left and !root->right)) return;
        if(root->left){
            int dif = abs(root->val - findmax(root->left));
            res = min(res,dif);
            helpfind(root->left,res);
        }
        if(root->right){
            int dif = abs(root->val - findmin(root->right));
            res = min(res,dif);
            helpfind(root->right,res);
        }
    }
    int findmin(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return root->val;
        else return findmin(root->left);
    }
    int findmax(TreeNode* root){
        if(!root) return 0;
        if(!root->right) return root->val;
        else return findmax(root->right);
    }
};

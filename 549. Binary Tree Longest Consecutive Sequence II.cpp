/*
Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.

Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.

Example 1:
Input:
        1
       / \
      2   3
Output: 2
Explanation: The longest consecutive path is [1, 2] or [2, 1].
Example 2:
Input:
        2
       / \
      1   3
Output: 3
Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
*/

class Solution {
public:
    Solution():m(0){}
    int longestConsecutive(TreeNode* root) {
        helpfind(root);
        return m;
    }
    vector<int> helpfind(TreeNode* root){
        if(!root) return vector<int>(4,0);
        vector<int> res(4,1);
        if(root->left){
            vector<int> left = helpfind(root->left);
            if(root->val == root->left->val +1){
                res[0] = max(left[0],left[2])+1;
            }
            else if(root->val == root->left->val -1){
                res[1] = max(left[1],left[3])+1;
            }
        }
        if(root->right){
            vector<int> right = helpfind(root->right);
            if(root->val == root->right->val + 1){
                res[2] = max(right[0],right[2])+1;
            }
            else if(root->val == root->right->val -1){
                res[3] = max(right[1],right[3])+1;
            }
        }
        m = max(m,max(res[1]+res[2],res[0]+res[3])-1);
        return res;
    }
    int m;
};

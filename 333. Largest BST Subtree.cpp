/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
*/
class Solution {
public:
int largestBSTSubtree(TreeNode* root) {
    if(!root) return 0;
    //unordered_map<TreeNode*,pair<int,bool>> mymap;
    vector<int> res=help(root);
    return res.back();
    }
    vector<int> help(TreeNode* root) {
        //if(!root) return {0,INT_MIN,INT_MAX,0};
        //cout<<"here"<<endl;
        if(!root->left and !root->right) return {1,root->val,root->val,1};
        //int sum=0;
        vector<int> left(4,0),right(4,0),res(4,0);
        if(root->left)
            left=help(root->left);
        else{
            left[0]=1;left[1]=left[2]=root->val;left[3]=0;
        }
        if(root->right)
            right=help(root->right);
        else{
            right[0]=1;right[1]=right[2]=root->val;right[3]=0;
        }
        if(left[0] and right[0]){
            if((!root->left or root->val>left[2]) and (!root->right or root->val<right[1])){
                res[0]=1;res[1]=left[1];res[2]=right[2];res[3]=left[3]+right[3]+1;
            }
            else{
                res[0]=0;res[1]=left[1];res[2]=right[2];res[3]=max(left[3],right[3]);
            }
        }
        else{
            res[0]=0;res[1]=left[1];res[2]=right[2];res[3]=max(left[3],right[3]);
        }
        return res;
    }
};

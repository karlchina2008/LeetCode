/*
Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, 
flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
*/
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        stack<TreeNode*> mystack;
        TreeNode *new_root,*temp_root,*temp=root;
        while(temp){
            mystack.push(temp);
            temp=temp->left;
        }
        temp_root=mystack.top();mystack.pop();
        new_root=temp_root;
        while(!mystack.empty()){
            temp=mystack.top();mystack.pop();
            temp_root->right=temp;temp_root->left=temp->right;
            temp_root=temp;
        }
        root->left=root->right=NULL;
        return new_root;
    }
    
};

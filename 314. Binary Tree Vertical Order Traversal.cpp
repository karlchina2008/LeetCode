/*
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.
*/
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        map<int,vector<int>> res;
        queue<pair<int,TreeNode*>> myqueue;
        myqueue.push({0,root});
        while(!myqueue.empty()){
            auto temp=myqueue.front();
            myqueue.pop();
            res[temp.first].push_back(temp.second->val);
            if(temp.second->left) myqueue.push({temp.first-1,temp.second->left});
            if(temp.second->right) myqueue.push({temp.first+1,temp.second->right});
        }
        for(auto node:res){
            result.push_back(node.second);
        }
        return result;
    }
};

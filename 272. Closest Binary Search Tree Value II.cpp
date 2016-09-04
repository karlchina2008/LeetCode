/*
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
*/
class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        list<pair<int,double>> record;
        record=help(root,target);
        vector<int> res;
        int i=0;
        for(auto it:record){
            res.push_back(it.first);
            if(++i==k) break;
        }
        return res;
    }
    list<pair<int,double>> help(TreeNode* root,double &target){
        list<pair<int,double>> cur;
        if(!root) return cur;
        double res=abs(double(root->val)-target);
        list<pair<int,double>> left,right;
        left=help(root->left,target);right=help(root->right,target);
        if(root->val<target){
            if(right.empty()) {left.push_front({root->val,res});return left;}
            else{
                auto it=lower_bound(right.begin(),right.end(),res,[](pair<int,double> b,double a){return a>b.second;});
                right.insert(it,{root->val,res});
                auto it_left=left.begin();
                while(it!=right.end() and it_left!=left.end()){
                    if(it->second<=it_left->second) it++;
                    else{
                        right.insert(it,*it_left);
                        it_left++;
                    }
                }
                while(it_left!=left.end()) {right.insert(it,*it_left);it_left++;}
                return right;
            }
        }
        else{
            if(left.empty()) {right.push_front({root->val,res}); return right;}
            else{
                auto it=lower_bound(left.begin(),left.end(),res,[](pair<int,double> b,double a){return a>b.second;});
                left.insert(it,{root->val,res});
                auto it_right=right.begin();
                while(it!=left.end() and it_right!=right.end()){
                    if(it->second<=it_right->second) it++;
                    else{
                        left.insert(it,*it_right);
                        it_right++;
                    }
                }
                while(it_right!=right.end()) {left.insert(it,*it_right);it_right++;}
                return left;
            }
        }
        return cur;
    }
};

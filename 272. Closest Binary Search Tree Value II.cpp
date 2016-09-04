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
    // brute force solution 
    // space complexity deque: O(K) ; stack: O(logN) stack; for stack part, we can remove it by morris traversal  
    // time complexity O(N)
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        if (root == NULL || k <= 0) { return vector<int>(); }
        deque<int> myQ; 
        stack<TreeNode *> ss; // use stack to do in-order search 
        while (root || !ss.empty()) {
            while(root) {
                ss.push(root);
                root = root->left;
            } 
            root = ss.top();
            ss.pop();
            // let's process root now
            if (myQ.size() < k) {
                myQ.push_back(root->val);
            } else { // size == k, 
                // if root->val is too small, update queue; otherwise, compare with queue's front
                if (target > root->val || (abs(target - root->val) < abs(target - myQ.front()))) {
                    myQ.push_back(root->val);
                    myQ.pop_front();
                } else {  
                    break; 
                }
            }
            // move to next one 
            root = root->right;
        }
        return vector<int>(myQ.begin(), myQ.end());
    }
};


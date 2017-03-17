/*
You need to construct a binary tree from a string consisting of parenthesis and integers.

The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

You always start to construct the left child node of the parent first if it exists.
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
    TreeNode* str2tree(string s) {
        if(s.empty()) return NULL;
        int n = s.size();
        TreeNode* root;
        if(s[0] != '-'){
            int i = 0;
            while( i < n and s[i] != '(') i++;
            root = new TreeNode(stoi(s.substr(0,i)));
        }
        else{
            int i = 1;
            while( i < n and s[i] != '(') i++;
            root = new TreeNode(-stoi(s.substr(1,i-1)));
        }
        int left = 0;
        int start = 0,end = 0;
        string s1,s2;
        for(int i = 0; i < n; i++){
            auto c = s[i];
            if(c == '(') { if((++left) == 1) start = i;}
            else if(c == ')') {if((--left) == 0) {end = i;s1 = s.substr(start+1,end-start-1);break;}}
        }
        left = 0;
        for(int i = end+1; i < n; i++){
            auto c = s[i];
            if(c == '(') {left++; if(left == 1) start = i;}
            else if(c == ')') {left--; if(left == 0) {end = i;s2 = s.substr(start+1,end-start-1);break;}}
        }
        //cout << s1 << " " << s2 << endl;
        
        root->left = str2tree(s1);
        root->right = str2tree(s2);
        return root;
    }
    
};

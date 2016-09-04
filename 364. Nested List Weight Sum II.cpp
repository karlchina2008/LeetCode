/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e.,
the leaf level integers have weight 1, and the root level integers have the largest weight.
*/
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for(auto ni : nestedList) {
            dfs(ni, 0, result);
        }
        //post processing 
        int sum = 0;
        for(int i = result.size()-1,level = 1; i >=0; i--, level++) {
            sum += result[i]*level;
        }
        return sum;
    }
private:
    void dfs(NestedInteger &ni, int depth, vector<int> & result) {
        if(result.size() < depth+1) result.resize(depth+1);
        if(ni.isInteger()) {
            result[depth] += ni.getInteger();
        } else {
            for(auto n_ni : ni.getList()) {
                dfs(n_ni, depth+1, result);
            }
        }
        
    }
};

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        unordered_set<int> myset;
        for(auto num:nums){
            if(num>0) myset.insert(num);
        }
        if(myset.count(1)==0) return 1;
        int res=INT_MAX;
        for(auto num:myset){
            if(num-1>0){
                if(myset.count(num-1)==0) res=min(res,num-1);
            }
            if(myset.count(num+1)==0) res=min(res,num+1);
        }
        return res;
    }
};

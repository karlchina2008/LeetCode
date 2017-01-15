/*
Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

Example 1:
Input: [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
    After flipping, the maximum number of consecutive 1s is 4.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<pair<int,int>> mypair;
        int i = 0, len = nums.size();
        while (i < len){
            if(nums[i] == 0){
                ++i;
                continue;
            }
            int start = i;
            while (i < len and nums[i] == 1) ++i;
            mypair.emplace_back(start,i-1);
        }
        if(mypair.empty()) return 1;
        int res = mypair[0].second-mypair[0].first+2, temp = 0;
        for (int i = 1; i < mypair.size(); i++){
            if( mypair[i].first - mypair[i-1].second == 2) res = max( res, mypair[i].second - mypair[i-1].first+1);
            else{
                res = max( res, mypair[i].second - mypair[i].first+2);
            }
        }
        return min(len,res);
    }
};

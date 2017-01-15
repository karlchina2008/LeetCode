/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
*/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = INT_MIN,temp = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) temp++;
            else{
                res = max(res,temp);
                temp = 0;
            }
        }
        res = max(res,temp);
        return max(0,res);
    }
};

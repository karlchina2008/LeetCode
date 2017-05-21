/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int i = 0, n = nums.size(),slow = 0,fast = 0;
        while ( i+1 < n){
            while(i+1 < n and nums[i+1] == nums[i] ) i++;
            i++;
            int mark = i;
            if(i < n and (nums[i] - nums[i-1]) == 1){
                while( i+1 < n and nums[i+1] == nums[i]) i++;
                res = max(res, i - slow + 1);
            }
            slow = mark;
        }
        return res;
    }
};

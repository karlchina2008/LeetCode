/*

Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3

*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int res = 0, n = nums.size();
        for(int i = 0; i < nums.size()-2; i++){
            if(nums[i] == 0 ) continue;
            for(int j = i+1; j < nums.size()-1;j++){
                int sum = nums[i] + nums[j];
                auto it = lower_bound(nums.begin(),nums.end(),sum);
                int dist = (nums.end() - it);
                res += (n - dist - j -1);
                //cout << res << endl;
            }
        }
        return res;
    }
};

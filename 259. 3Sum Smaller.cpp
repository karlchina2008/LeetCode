/*
Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size()-2;i++){
            int left=i+1,right=nums.size()-1;
            int sub_target=target-nums[i];
            while(left<right){
                if(nums[left]+nums[right]<sub_target) {sum+=right-left;left++;}
                else right--;
            }
        }
        return sum;
    }
};

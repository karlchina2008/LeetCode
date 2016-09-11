/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size(),i=0,j=n-1,min_num=INT_MAX,max_num=INT_MIN;
        if(n<3) return false;
        vector<int> min_v(n),max_v(n);
        for(int i=0;i<n;i++){
            min_num=min_num>nums[i]?nums[i]:min_num;
            min_v[i]=min_num;
            max_num=max_num<nums[n-1-i]?nums[n-1-i]:max_num;
            max_v[n-1-i]=max_num;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>min_v[i] and nums[i]<max_v[i]) return true;
        }
        return false;
    }
};

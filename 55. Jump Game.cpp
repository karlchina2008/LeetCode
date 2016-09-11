/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return true;
        int i=0,pos=nums[0],max_s=pos;
        while(i<n){
            for(int j=i;j<=min(n-1,pos);j++){
                pos=(nums[j]+j)>pos?(nums[j]+j):pos;
            }
            //cout<<pos<<endl;
            if(pos>=n-1) return true;
            if(i==pos) return false;
            i=pos;
        }
        return false;
    }
};

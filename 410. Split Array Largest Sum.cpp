*/
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.
*/
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0,max_num=INT_MIN;
        for(auto num:nums){
            sum+=num;
            max_num=max(max_num,num);
        }
        while(max_num<sum){
            int mid=(sum-max_num)/2+max_num;
            //cout<<"here"<<endl;
            if(cansplit(nums,m,mid)) sum=mid;
            else max_num=mid+1;
            //cout<<"here_1"<<endl;
        }
        return max_num;
    }
    bool cansplit(vector<int> &nums,int cuts,int sum){
        int count=0,res=0;
        for(auto num:nums){
            res+=num;
            if(res>sum){
                res=num;
                if(++count>=cuts) return false;
            }
        }
        return true;
    }
};

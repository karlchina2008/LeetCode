/*
Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].
*/
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.empty()){
            if(lower<upper)
                res.push_back(to_string(lower)+"->"+to_string(upper));
            else
                res.push_back(to_string(lower));
            return res;
        }
        int right=nums.size();
        int cur=0;
        if(nums[cur]-lower==1){
            res.push_back(to_string(lower));
        }
        if(nums[cur]-lower>1){
            res.push_back(to_string(lower)+"->"+to_string(nums[cur]-1));
        }
        while(cur<right-1){
            if(nums[cur+1]-nums[cur]<=1){
                ++cur;
                continue;
            }
            if(nums[cur+1]-nums[cur]==2){
                res.push_back(to_string(nums[cur]+1));
                cur++;continue;
            }
            if(nums[cur+1]-nums[cur]>2){
                res.push_back(to_string(nums[cur]+1)+"->"+to_string(nums[cur+1]-1));
                ++cur;continue;
            }
        }
        if(upper-nums[right-1]==1)
            res.push_back(to_string(upper));
        if(upper-nums[right-1]>1)
            res.push_back(to_string(nums[right-1]+1)+"->"+to_string(upper));
        return res;
    }
};

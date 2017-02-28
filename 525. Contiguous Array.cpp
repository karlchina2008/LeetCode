/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
*/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        //cout << n << endl;
        vector<int> sum(n,0);
        int temp = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            temp += (nums[i] == 0?-1:1);
            sum[i] = temp;
            //cout << temp << endl;
        }
        unordered_map<int,vector<int>> positions;
        for(int i = 0; i < n; i++){
            positions[sum[i]].push_back(i);
        }
        for(auto p : positions){
            if(p.first == 0){
                res = res < (p.second.back()+1) ? (p.second.back()+1):res;
                continue;
            }
            int temp_1 = p.second.back() - p.second.front();
            //cout << temp_1 << endl;
            res = res < temp_1 ? temp_1:res;
        }
        return res;
    }
};

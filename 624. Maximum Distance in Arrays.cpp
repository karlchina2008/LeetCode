/*
Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

Example 1:
Input: 
[[1,2,3],
 [4,5],
 [1,2,3]]
Output: 4
Explanation: 
One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
*/
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int,int>> min_array,max_array;
        for(int i = 0; i < arrays.size(); i++){
            min_array.push_back({i,arrays[i].front()});
            max_array.push_back({i,arrays[i].back()});
        }
        sort(min_array.begin(),min_array.end(),[](pair<int,int> a, pair<int,int> b){return a.second < b.second;});
        sort(max_array.begin(),max_array.end(),[](pair<int,int> a, pair<int,int> b){return a.second > b.second;});
        if(min_array.front().first != max_array.front().first) return max_array.front().second - min_array.front().second;
        else return max(max_array[1].second - min_array[0].second,max_array[0].second - min_array[1].second);
    }
};

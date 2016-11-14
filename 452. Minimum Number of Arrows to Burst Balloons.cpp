/*
There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.
*/
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),[](pair<int,int> a,pair<int,int> b){if(a.first == b.first) return a.second <= b.second;else return a.first < b.first;});
        int i=0,count =0;
        while (i < points.size()){
            int j = i+1, right = points[i].second;
            while (j < points.size() and points[j].first <= right){
                right = right <= points[j].second ? right : points[j].second;
                ++j;
            }
            count++;
            i = j;
        }
        return count;
    }
};

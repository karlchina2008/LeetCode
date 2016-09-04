/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
*/
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        int n=intervals.size(),res=0;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<=b.start;});
        priority_queue<int,vector<int>,greater<int>> q;
        //q.push(intervals[0].end);
        for(int i=0;i<intervals.size();i++){
            while(!q.empty() and intervals[i].start>=q.top()){
                q.pop();
            }
            q.push(intervals[i].end);
            res=q.size()>res?q.size():res;
        }
        return res;
    }
};

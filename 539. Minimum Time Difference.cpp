/*
Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<pair<int,int>> new_times;
        for(auto times:timePoints){
            new_times.push_back(parse(times));
        }
        sort(new_times.begin(),new_times.end(),[](pair<int,int> a,pair<int,int> b){if(a.first == b.first) return a.second < b.second;else return a.first < b.first;});
        int res = INT_MAX;
        for(int i = 0; i < n-1; i++){
            int temp = (new_times[i+1].first - new_times[i].first)*60 + new_times[i+1].second - new_times[i].second;
            res = min(res,temp);
        }
        res = min(res,(24+new_times[0].first - new_times[n-1].first)*60 + new_times[0].second - new_times[n-1].second);
        return res;
    }
    
    pair<int,int> parse(string& times){
        pair<int,int> res;
        res.first = stoi(times.substr(0,2));
        res.second = stoi(times.substr(3,2));
        return res;
    }
};

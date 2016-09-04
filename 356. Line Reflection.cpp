/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
*/
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if(points.size()<=1) return true;
        vector<pair<int,int>> new_points;
        sort(points.begin(),points.end(),[](pair<int,int> a,pair<int,int> b){if(a.first==b.first) return a.second<b.second;else return a.first<b.first;});
        new_points.push_back(points.front());
        int i=1;
        while(i<points.size()){
            if(points[i]!=points[i-1]) new_points.push_back(points[i]);
            i++;
        }
        //cout<<new_points.size()<<endl;
        sort(new_points.begin(),new_points.begin()+new_points.size()/2,[](pair<int,int> a,pair<int,int> b){if(a.first==b.first) return a.second<b.second;else return a.first<b.first;});
        sort(new_points.end()-new_points.size()/2,new_points.end(),[](pair<int,int> a,pair<int,int> b){if(a.first==b.first) return a.second>b.second;else return a.first<b.first;});
        int left=0,right=new_points.size()-1,mid=new_points[left].first+new_points[right].first;
        while(left<=right){
            if(new_points[left].first*2==mid){left++;continue;}
            if(new_points[left].first+new_points[right].first!=mid or new_points[left].second!=new_points[right].second) return false;
            else{
                left++;right--;
            }
        }
        return true;
    }
};

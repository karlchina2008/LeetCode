/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float,int> linemap;
        map<pair<int,int>,int> pointmap;
        //vector<pair<Point,int>> pointmap;
        //sort(points.begin(),points.end(),[](const Point &a,const Point &b){return a.x<b.x;});
        int i=0,n=points.size(),left,temp,count=0;
        if(n<=2) return n;
        for(auto point:points){
            pointmap[make_pair(point.x,point.y)]++;
           // cout<<pointmap[make_pair(point.x,point.y)]<<endl;
        }
        for(auto point_1=pointmap.begin();point_1!=pointmap.end();point_1++){
            temp=0;
            for(auto point_2=point_1;point_2!=pointmap.end();point_2++){
                if((point_1->first).first==(point_2->first).first){
                    temp+=point_2->second;
                    continue;
                }
                linemap[float((point_2->first).second-(point_1->first).second)/float((point_2->first).first-(point_1->first).first)]+=point_2->second;
            }
            //cout<<"here"<<endl;
            for(auto it:linemap)
                count=max(count,it.second+point_1->second);
            //cout<<temp<<endl;
            count=max(count,temp);
            linemap.clear();
        }
        return count;
    }
};

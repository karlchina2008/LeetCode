/*
There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

Example 1:
Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
Explanation:

Example 2:
Input: [[1,2],[2,2],[4,2]]
Output: [[1,2],[2,2],[4,2]]
Explanation:

Even you only have trees in a line, you need to use rope to enclose them. 
Note:

All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
All input integers will range from 0 to 100.
The garden has at least one tree.
All coordinates are distinct.
Input points have NO order. No order required for output.

*/
class Solution {
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int min_y = 101,mark = 0,mark_1 = 0,n = points.size();
        for(int i = 0; i < n; i++){
            Point p = points[i];
            if(p.y < min_y){
                min_y = p.y;
                mark = i;
            }
            else if(p.y == min_y and p.x < points[mark].x){
                mark = i;
            }
        }
        //cout << mark<< endl;
        unordered_set<int> myset;
        myset.insert(mark);
        int cur_x = 1,cur_y = 0;
        double cur_dist = 1.0;
        while(1){
            int dist = INT_MAX;
            double angle = -2;
            for(int i = 0; i < n; i++){
                if(i == mark) continue;
                int x_temp = points[i].x - points[mark].x, y_temp = points[i].y - points[mark].y;
                double dist_temp = sqrt(x_temp*x_temp+y_temp*y_temp);
                double theta = double(cur_x*x_temp + cur_y*y_temp)/cur_dist/dist_temp;
                //cout << "cos " <<theta << " dist " <<dist_temp << endl;
                if(theta - angle > 0.00001 ){mark_1 = i;dist = dist_temp;angle = theta;}
                else if(abs(theta-angle) < 0.00001 and dist_temp < dist){
                    mark_1 = i; dist = dist_temp;
                }
            }
            //cout << mark_1 << endl;
            if(myset.find(mark_1) != myset.end()) break;
            myset.insert(mark_1);
            swap(mark,mark_1);
            cur_x = points[mark].x - points[mark_1].x,cur_y = points[mark].y - points[mark_1].y;
            cur_dist = sqrt(cur_x*cur_x + cur_y*cur_y);
        }
        vector<Point> res;
        for(auto s : myset){
            res.push_back(points[s]);
        }
        return res;
    }
};

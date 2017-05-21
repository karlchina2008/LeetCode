/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<pair<int,int>> new_vector(4);
        new_vector[0] = make_pair(p1[0],p1[1]);
        new_vector[1] = make_pair(p2[0],p2[1]);
        new_vector[2] = make_pair(p3[0],p3[1]);
        new_vector[3] = make_pair(p4[0],p4[1]);
        
        sort(new_vector.begin(),new_vector.end(),[](pair<int,int> a, pair<int,int> b){
            if(a.first == b.first) return a.second <= b.second;
            else return a.first < b.first;
        });
        int dx_1 = new_vector[1].first - new_vector[0].first,dy_1 = new_vector[1].second - new_vector[0].second;
        int dx_2 = new_vector[2].first - new_vector[0].first,dy_2 = new_vector[2].second - new_vector[0].second;
        int dx_3 = new_vector[3].first - new_vector[0].first,dy_3 = new_vector[3].second - new_vector[0].second;
        
        if(dx_1*dx_1 + dy_1*dy_1 == dx_2*dx_2 + dy_2*dy_2 and dx_1*dx_2 + dy_1*dy_2 == 0 and dx_3*dx_1 + dy_3*dy_1 == dx_3*dx_2 + dy_3*dy_2)
            return true;
        else
            return false;
    }
};

/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        vector<int> x,y;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]) x.push_back(i);
        for(int j=0;j<m;j++)
            for(int i=0;i<n;i++)
                if(grid[i][j]) y.push_back(j);
        if(x.empty()) return 0;
        int x_mid=x[x.size()/2],y_mid=y[y.size()/2];
        int dist_x=0,dist_y=0;
        for(int i=0;i<x.size();i++)
            dist_x+=abs(x[i]-x_mid);
        for(int i=0;i<y.size();i++)
            dist_y+=abs(y[i]-y_mid);
        return dist_x+dist_y;
    }
};

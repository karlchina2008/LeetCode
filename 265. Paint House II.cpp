/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        if(n==0) return 0;
        int m=costs[0].size();
        vector<int> d(m,0);
        int c_1,s_1=INT_MAX,s_2=INT_MAX;
        for(int i=0;i<m;i++){
            d[i]=costs[0][i];
            if(s_1>d[i]){
                s_1=d[i];c_1=i;
            }
        }
        for(int i=0;i<m;i++){
            if(i!=c_1 and s_2>d[i]){
                s_2=d[i];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==c_1)
                    d[j]=costs[i][j]+s_2;
                else
                    d[j]=costs[i][j]+s_1;
            }
            s_1=s_2=INT_MAX;
            for(int j=0;j<m;j++){
                if(s_1>d[j]){
                    s_1=d[j];c_1=j;//min value;
                }
            }
            for(int j=0;j<m;j++){
                if(j!=c_1 and s_2>d[j]){
                    s_2=d[j];//second min value;
                }
            }
        }
        int res=INT_MAX;
        for(int i=0;i<m;i++){
            res=res>d[i]?d[i]:res;
        }
        return res;
    }
};

/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.
*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;
        int m=grid[0].size();
        vector<vector<pair<int,int>>> row(n,vector<pair<int,int>>()),col(m,vector<pair<int,int>>());
        int sum;
        for(int i=0;i<n;i++){
            sum=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]!='W'){
                    if(grid[i][j]=='E')
                        sum++;
                }
                else{
                    row[i].emplace_back(j,sum);
                    sum=0;
                }
            }
            row[i].emplace_back(m,sum);
            //cout<<row[i].back().first<<" "<<row[i].back().second<<endl;
        }
        for(int j=0;j<m;j++){
            sum=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]!='W'){
                    if(grid[i][j]=='E')
                        sum++;
                }
                else{
                    col[j].emplace_back(i,sum);
                    sum=0;
                }
            }
            col[j].emplace_back(n,sum);
            //cout<<col[j].back().first<<" "<<col[j].back().second<<endl;
        }
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    auto it_1=upper_bound(row[i].begin(),row[i].end(),j,[](int val,pair<int,int> x){return val<x.first;});
                    auto it_2=upper_bound(col[j].begin(),col[j].end(),i,[](int val,pair<int,int> x){return val<x.first;});
                    res=max(res,it_1->second+it_2->second);
                }
            }
        return res;
    }
};

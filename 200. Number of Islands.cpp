/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=m==0?0:grid[0].size(),count=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    helpcount(grid,i,j,m,n);
                    count++;
                }
            }
        return count;
    
    }
    void helpcount(vector<vector<char>>& grid, int i,int j,int m,int n){
        if(i+1<m and grid[i+1][j]=='1'){
            grid[i+1][j]='0';
            helpcount(grid,i+1,j,m,n);
        }
        if(i-1>=0 and grid[i-1][j]=='1'){
            grid[i-1][j]='0';
            helpcount(grid,i-1,j,m,n);
        }
        if(j+1<n and grid[i][j+1]=='1'){
            grid[i][j+1]='0';
            helpcount(grid,i,j+1,m,n);
        }
        if(j-1>=0 and grid[i][j-1]=='1'){
            grid[i][j-1]='0';
            helpcount(grid,i,j-1,m,n);
        }
    }
};

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n = m ==0 ? 0 : board[0].size();
        vector< vector<pair<int,int>> > find(m,vector<pair<int,int>>(n));
        vector< vector<int> > size(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                find[i][j]=make_pair(i,j);
                if(board[i][j]=='O') size[i][j]=1;
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    if(i+1<m and board[i+1][j]=='O'){
                        connect(find,size,i,j,i+1,j,m,n);
                    }
                    if(j+1<n and board[i][j+1]=='O'){
                        connect(find,size,i,j,i,j+1,m,n);
                    }
                }
            }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    pair<int,int> temp=findroot(find,i,j);
                    if(temp.first>0 and temp.first<m-1 and temp.second>0 and temp.second<n-1)
                        board[i][j]='X';
                }
            }
        
    }
    pair<int,int> findroot(vector<vector<pair<int,int>>>& find,int i,int j){
        pair<int,int> temp = find[i][j];
        int i_temp=i , j_temp=j;
        while(temp != find[temp.first][temp.second]){
            find[i_temp][j_temp] = find[temp.first][temp.second];
            temp = find[temp.first][temp.second];
            i_temp = temp.first,j_temp=temp.second;
            temp = find[i_temp][j_temp];
        }
        return temp;
    }
    void connect(vector<vector<pair<int,int>>>& find,vector< vector<int> >& size,int i1,int j1,int i2,int j2,int& m,int& n){
        pair<int,int> temp_1=findroot(find,i1,j1),temp_2=findroot(find,i2,j2);
        if(temp_1!=temp_2){
                        if(temp_1.first==0 or temp_1.first==m-1 or temp_1.second==0 or temp_1.second==n-1){
                            find[temp_2.first][temp_2.second]=temp_1;
                            size[temp_1.first][temp_1.second]+=size[temp_2.first][temp_2.second];
                        }
                        else if(temp_2.first==0 or temp_2.first==m-1 or temp_2.second==0 or temp_2.second==n-1){
                            find[temp_1.first][temp_1.second]=temp_2;
                            size[temp_2.first][temp_2.second]+=size[temp_1.first][temp_1.second];
                        }
                        else if(size[temp_1.first][temp_1.second]>size[temp_2.first][temp_2.second]){
                            find[temp_2.first][temp_2.second]=temp_1;
                            size[temp_1.first][temp_1.second]+=size[temp_2.first][temp_2.second];
                        }
                        else{
                            find[temp_1.first][temp_1.second]=temp_2;
                            size[temp_2.first][temp_2.second]+=size[temp_1.first][temp_1.second];
                        }
                    }
    }
};

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n=rooms.size(),m=n==0?0:rooms[0].size();
        vector<int> dir={0,1,0,-1,0};
        queue<pair<int,int>> myque;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(rooms[i][j]==0){
                    int dist=0;
                    myque.push({i,j});
                    while(!myque.empty()){
                        pair<int,int> top=myque.front();
                        myque.pop();
                        dist++;
                        for(int k=0;k<4;k++){
                            if(top.first+dir[k]>=0 and top.first+dir[k]<n and top.second+dir[k+1]>=0 and top.second+dir[k+1]<m){
                                if(rooms[top.first+dir[k]][top.second+dir[k+1]]!=-1 and rooms[top.first+dir[k]][top.second+dir[k+1]]>rooms[top.first][top.second]){
                                    myque.push({top.first+dir[k],top.second+dir[k+1]});
                                    rooms[top.first+dir[k]][top.second+dir[k+1]]=min(rooms[top.first+dir[k]][top.second+dir[k+1]],rooms[top.first][top.second]+1);
                                }
                            }
                        }
                    }
                }
    }
};

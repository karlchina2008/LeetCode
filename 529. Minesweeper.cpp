/*
You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
Example 1:
Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:
Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:
*/
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0],col = click[1];
        int m = board.size(),n = m == 0 ? 0:board[0].size();
        if(board[click[0]][click[1]] == 'M') board[click[0]][click[1]] = 'X';
        if(board[row][col] == 'E') update(board,row,col,m,n);
        return board;
    }
    void update(vector<vector<char>>& board,int row,int col,int m, int n){
        if(board[row][col] == 'E'){
        int dir_1[5] = {1,0,-1,0,1},dir_2[5] = {1,1,-1,-1,1};
        int count = 0;
        for(int i = 0; i < 4; i++){
            int new_row = row+dir_1[i],new_col = col + dir_1[i+1];
            if(new_row >= 0 and new_row < m and new_col >=0 and new_col < n){
                if(board[new_row][new_col] == 'M') count++;
            }
        }
        for(int i = 0; i < 4; i++){
            int new_row = row+dir_2[i],new_col = col + dir_2[i+1];
            if(new_row >= 0 and new_row < m and new_col >=0 and new_col < n){
                if(board[new_row][new_col] == 'M') count++;
            }
        }
        if(count > 0) board[row][col] = '0'+count;
        else 
        {   board[row][col] = 'B';
            for(int i = 0; i < 4; i++){
                int new_row = row+dir_1[i],new_col = col + dir_1[i+1];
                if(new_row >= 0 and new_row < m and new_col >=0 and new_col < n){
                    update(board,new_row,new_col,m,n);
                }
            }
            for(int i = 0; i < 4; i++){
            int new_row = row+dir_2[i],new_col = col + dir_2[i+1];
            if(new_row >= 0 and new_row < m and new_col >=0 and new_col < n){
                update(board,new_row,new_col,m,n);
            }
        }
        }
        }
    }
};

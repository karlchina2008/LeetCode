/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.
*/

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int max_diff = INT_MIN,res = 0;
        for(auto nut:nuts){
            int temp_1 = abs(nut[0] - squirrel[0])+abs(nut[1] - squirrel[1]);
            int temp_2 = abs(nut[0] - tree[0])+abs(nut[1] - tree[1]);
            res += 2*temp_2;
            max_diff = max(max_diff,temp_2-temp_1);
        }
        return res - max_diff;
    }
};

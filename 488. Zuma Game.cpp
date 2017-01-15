/*
Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

Examples:

Input: "WRRBBW", "RB"
Output: -1
Explanation: WRRBBW -> WRR[R]BBW -> WBBW -> WBB[B]W -> WW

Input: "WWRRBBWW", "WRBRW"
Output: 2
Explanation: WWRRBBWW -> WWRR[R]BBWW -> WWBBWW -> WWBB[B]WW -> WWWW -> empty

Input:"G", "GGGGG"
Output: 2
Explanation: G -> G[G] -> GG[G] -> empty 

Input: "RBYYBBRRB", "YRBGB"
Output: 3
Explanation: RBYYBBRRB -> RBYY[Y]BBRRB -> RBBBRRB -> RRRB -> B -> B[B] -> BB[B] -> empty 
*/
class Solution {
public:
    Solution(){ res = 6;}
    
    int findMinStep(string board, string hand) {
        string temp = "";
        vector<int> count;
        int len = hand.size();
        vector<bool> used(len,false);
        int i = 0, sum = 0;
        while (i < board.size()){
            temp.push_back(board[i]);
            if ( i+1 < board.size() and board[i+1] == board[i]) {++i;count.push_back(2);}
            else count.push_back(1);
            sum += count.back();
            ++i;
        }
        int m = temp.size();
        vector<int> count_2 = count;
        helpfind(temp,count,count_2,hand,used,0,sum,m,len);
        return res > 5?-1:res;
    }
    void helpfind(string& temp,vector<int> count,vector<int> count_2,string& hand,vector<bool>& used,int cur, int sum, int &m, int &n){
        if( sum == 0){
            //cout << sum << " " << cur << endl;
            res = min(res,cur);
            return;
        }
        if( cur >= n) return;
        for(int i = 0; i < n; i++){
            if (!used[i]){
                for(int j = 0; j< m; j++){
                    if (temp[j] == hand[i] and count[j] != 0){
                        vector<int> count_temp = count,count_temp_2= count_2;
                        int t_1 = sum;
                        count[j]++;
                        used[i] = true;
                        cur++;
                        //cout << hand[i] << " " << count[j] << endl;
                        if (count[j] >= 3){
                            sum -= count_2[j];
                            count[j] = 0;
                            count_2[j] = 0;
                            if(j > 0 and j < m-1){
                                int start = j-1, end = j+1, num;
                                while (start >=0 and end <= m-1){
                                    while (start >=0 and count[start] == 0) start--;
                                    while (end <= m-1 and count[end] ==0) end++;
                                if (start >=0 and end <= m-1){
                                    if(temp[start] == temp[end]) {
                                        count[start] = count[start]+count[end];
                                        count_2[start] = count_2[start]+ count_2[end];
                                        count[end] = 0;
                                        count_2[end] = 0;
                                        //cout << count[start] << " " << count[end] << endl;
                                        if(count[start] >= 3){
                                            sum = sum - count_2[start];
                                            count[start] = 0;
                                            count_2[start] = 0;
                                            start --;
                                            end++;
                                        }
                                        else 
                                            break;
                                    }
                                    else 
                                            break;
                                }
                                else break;
                            }
                            }
                        }
                        //cout << sum << endl;
                        helpfind(temp,count,count_2,hand,used,cur,sum,m,n);
                        used[i] = false;
                        cur--;
                        sum = t_1;
                        swap(count,count_temp);
                        swap(count_2,count_temp_2);
                    }
                }
            }
        }
        return;
    }
    
    int res;
};

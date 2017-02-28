/*
Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

The number at the ith position is divisible by i.
i is divisible by the number at the ith position.
Now given N, how many beautiful arrangements can you construct?

Example 1:
Input: 2
Output: 2
Explanation: 

The first beautiful arrangement is [1, 2]:

Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

The second beautiful arrangement is [2, 1]:

Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
*/
class Solution {
public:
    int countArrangement(int N) {
        unordered_map<int,vector<int>> myfactor;
        vector<bool> used(N,false);
        int count = 0;
        for(int i = 1; i <= N; i++){
            myfactor[i] = factor(i,N);
        }
        helpcount(myfactor,used,count,1,N);
        return count;
    }
    
    vector<int> factor(int n,int N){
        vector<int> res;
        for(int i = 1;i <= n; i++)
            if ( n % i == 0) res.push_back(i);
        for(int i = 2; i*n<= N; i++)
            res.push_back(i*n);
        return res;
    }
    void helpcount(unordered_map<int,vector<int>>& myfactor,vector<bool>& used,int& count,int cur,int& N){
        if(cur == N+1){
            count++;
            return;
        }
        vector<int> temp = myfactor[cur];
        for(auto factor:temp){
            if(!used[factor]){
                used[factor] = true;
                helpcount(myfactor,used,count,cur+1,N);
                used[factor] = false;
            }
        }
        return;
    }
};

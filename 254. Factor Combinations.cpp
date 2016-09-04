/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
*/
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        getResult(res,cur,n,2);
        return res;
    }
    
    void getResult(vector<vector<int>> &res,vector<int> &cur,int n,int min_factor){
        if(n>=min_factor and !cur.empty()){
            cur.push_back(n);
            res.push_back(cur);
            cur.pop_back();
            //return;
        }
        for(int i=min_factor;i<=n/i;i++){
            if(n%i==0){
                cur.push_back(i);
                //cur.push_back(n/i);
                getResult(res,cur,n/i,i);
                cur.pop_back();
                //cout<<"here"<<endl;
            }
        }
    }
};

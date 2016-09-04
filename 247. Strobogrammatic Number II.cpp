/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        string gram="01869";
        unordered_map<char,char> mymap={{'0','0'},{'1','1'},{'8','8'},{'6','9'},{'9','6'}};
        vector<string> res;
        int m=n/2;
        help(res,gram,m,"");
        if(n%2==0){
            for(int i=0;i<res.size();i++){
                string s=res[i];
                for(int j=s.size()-1;j>=0;j--)
                    res[i]+=mymap[s[j]];
            }
        }
        else{
            vector<string> res_1;
            for(int i=0;i<res.size();i++){
                string s;
                for(int j=res[i].size()-1;j>=0;j--)
                    s+=mymap[res[i][j]];
                for(int j=0;j<3;j++){
                    res_1.push_back(res[i]+gram[j]+s);
                }
            }
            return res_1;
        }
        return res;
    }
    
    void help(vector<string> &res,string &gram,int &m,string temp){
        if(temp.size()==m){
            res.push_back(temp);
            return;
        }
        int begin;
        if(temp.empty()) begin=1;
        else begin=0;
        for(int i=begin;i<5;i++){
            temp.push_back(gram[i]);
            help(res,gram,m,temp);
            temp.pop_back();
        }
    }
};

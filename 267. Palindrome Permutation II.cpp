/*
Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].
*/
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char,int> wordmap;
        for(int i=0;i<s.size();i++){
            wordmap[s[i]]++;
        }
        vector<string> res;
        char temp;
        int count=0,sum=0;
        for(auto it=wordmap.begin();it!=wordmap.end();it++){
            if(((*it).second)%2==1) {count++;temp=(*it).first;}
            sum+=((*it).second/=2);
        }
        if(count>=2) return res;
        help(wordmap,"",res,sum);
        if(count)
        for(int i=0;i<res.size();i++){
            string str=res[i];
            res[i]+=temp;
            for(int j=str.size()-1;j>=0;j--)
                res[i]+=str[j];
        }
        else
        for(int i=0;i<res.size();i++){
            string str=res[i];
            //res[i]+=temp;
            for(int j=str.size()-1;j>=0;j--)
                res[i]+=str[j];
        }
        return res;
    }
    void help(unordered_map<char,int> &wordmap,string s,vector<string> &res,int &n){
        if(s.size()==n){
            res.push_back(s);
            return;
        }
        for(auto it=wordmap.begin();it!=wordmap.end();it++){
            if((*it).second>0){
                s.push_back((*it).first);
                (*it).second--;
                help(wordmap,s,res,n);
                (*it).second++;
                s.pop_back();
            }
        }
    }
};

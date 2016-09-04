/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
Notes:
You may assume both pattern and str contains only lowercase letters.
*/
class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        vector<string> map(128,"");
        unordered_set<string> myset;
        return helpfind(map,myset,pattern,0,str,0);
    }
    bool helpfind(vector<string> &map,unordered_set<string> &myset,string &pattern,int pos,string &str,int cur){
        string temp;
        for(;pos<pattern.size();pos++){
            temp=map[pattern[pos]-'0'];
            if(!temp.empty()){
                if(cur+temp.size()-1>=str.size() or str.compare(cur,temp.size(),temp)!=0) return false;
                cur+=temp.size();
                //return helpfind(map,myset,pattern,i+1,str,temp.size()+cur);
            }
            else break;
        }
        if(pos==pattern.size()) return cur==str.size();
        temp="";
            for(int i=cur;i<(str.size()-pattern.size()+pos+1);i++){
                temp+=str[i];
                if(myset.find(temp)==myset.end()){
                    map[pattern[pos]-'0']=temp;
                    //cout<<temp<<" "<<pattern[pos]<<endl;
                    myset.insert(temp);
                    if(helpfind(map,myset,pattern,pos+1,str,i+1)) return true;
                    myset.erase(temp);//this has to be optimized; 
                    map[pattern[pos]-'0']="";
                    //temp.pop_back();
                }
            }
            return false;
    }
};

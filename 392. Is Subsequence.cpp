/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return help(t,s,0,0);
    }
    bool help(string &s,string &t,int s_pos,int t_pos){
        if(t.size()==t_pos) return true;
        else if(s_pos==s.size()) return false;
        int max_size=s.size()-(t.size()-t_pos)+1;
        for(int i=s_pos;i<max_size;i++){
            if(s[i]==t[t_pos]){
                if(help(s,t,i+1,t_pos+1)) return true;
            }
        }
        return false;
    }
};

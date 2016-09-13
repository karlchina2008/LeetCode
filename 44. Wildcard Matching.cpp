/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        return helpcheck(s.c_str(),p.c_str());
    }
    bool helpcheck(const char *s_pos,const char *p_pos){
        if(*s_pos=='\0'){
            if(*p_pos=='\0') return true;
            if(*p_pos!='*') return false;
        }
        if(*p_pos=='\0' and *s_pos!='\0') return false;
        if(*p_pos!='*' and *p_pos!='?' and *s_pos!=*p_pos) {return false;}
        while(*(p_pos)=='*' and *(p_pos+1)=='*') p_pos++;
        cout<<*p_pos<<" "<<*s_pos<<endl;
        if(*p_pos=='*'){
            int n=0;
            //if(*(p_pos+1)!=*s_pos and *(p_pos+1)!='.' and *s_pos!='\0') {cout<<"here 3"<<endl;return false;}
            if(helpcheck(s_pos,p_pos+1)) return true;// no repeating
            while(*(s_pos+n)!='\0'){
                if(*(s_pos+n)==*(p_pos+1) or *(p_pos+1)=='?'){
                    if(helpcheck(s_pos+n+1,p_pos+2)) return true;// repeat more than one time
                    break;
                }
                n++;
            }
            if(*(s_pos+n)=='\0') if(helpcheck(s_pos+n,p_pos+1)) return true;
        }
        if(*p_pos=='?' or *p_pos==*s_pos)
            if(helpcheck(s_pos+1,p_pos+1)) return true;
        return false;
    }
};

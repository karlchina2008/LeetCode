/*
Given two strings S and T, determine if they are both one edit distance apart.
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size()<t.size()) return isOneEditDistance(t,s);
        if(s.size()-t.size()>=2) return false;
        //cout<<"here_2"<<endl;
        if(s.size()==t.size()){
            int count=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!=t[i]) count++;
                if(count>=2) return false;
            }
            return count==0?false:true;
        }
        //cout<<"here_1"<<endl;
        
        //cout<<"here"<<endl;
        int i=0;
        while(i<t.size()){
            if(s[i]!=t[i]){
                break;
            }
            i++;
        }
        if(i==t.size()) return true;
        if(s[i+1]!=t[i]) return false;
        else{
            i++;
            while(i<t.size()){
                if(s[i+1]!=t[i]) return false;
                i++;
            }
            return true;
        }
        
    }
};

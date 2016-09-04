/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/
class Solution {
public:
    void reverseWords(string &s) {
        int l=0,r=s.size()-1;
        reverseword(s,l,r);
        while(l<=r){
            size_t pos=s.find_first_of(" ",l);
            if(pos!=string::npos){
                reverseword(s,l,pos-1);
                l=pos+1;
            }
            else {
                reverseword(s,l,r);
                break;
            }
        }
    }
    void reverseword(string &s,int l,int r){
        while(l<r){
            char temp;
            temp=s[r];
            s[r]=s[l];
            s[l]=temp;
            l++;r--;
        }
    }
};

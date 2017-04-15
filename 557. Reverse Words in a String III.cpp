/*
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
*/

class Solution {
public:
    string reverseWords(string s) {
        int i = 0,n = s.size();
        while( i < n){
            int i_temp = i;
            while(i < n and s[i] != ' ') i++;
            reverse(s,i_temp,i);
            i++;
        }
        return s;
    }
    
    void reverse(string& s,int l,int r){
        r = r-1;
        while(l < r)
            swap(s[l++],s[r--]);
    }
};

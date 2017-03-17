/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0, n = s.size();
        if(n <= k) reverse(s,0,n-1);
        else{
            int j = i+k-1;
            while (i < n){
                reverse(s,i,j);
                i += 2*k;
                j = min(n-1,i+k-1);
            }
        }
        return s;
    }
    void reverse(string& s ,int i ,int j){
        int start = i,end = j;
        while (start < end){
            swap(s[start++],s[end--]);
        }
    }
};

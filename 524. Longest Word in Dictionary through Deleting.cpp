/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output: 
"apple"
Example 2:
Input:
s = "abpcplea", d = ["a","b","c"]

Output: 
"a"
*/
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(auto str:d){
            int m = res.size(),n = str.size();
            if(n >= m and substrings(s,str)){
                //cout << str << endl;
                if( n > m) res = str;
                else if(n == m and str < res) res = str;
            }
        }
        return res;
    }
    bool substrings(string s_1,string s_2){
        int m = s_1.size(), n = s_2.size();
        if( m < n) return false;
        int i = 0;
        for(auto c:s_2){
            while(i < m and s_1[i] != c) ++i;
            if(i==m) return false;
            else ++i;
        }
        return true;
    }
};

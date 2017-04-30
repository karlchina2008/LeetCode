/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> mark_1(26,0),mark_2(26,0);
        int m = s1.size(), n = s2.size();
        for(auto s:s1){
            mark_1[s-'a']++;
        }
        for(int i = 0; i < m; i++){
            mark_2[s2[i] - 'a']++;
        }
        if(compare(mark_1,mark_2)) return true;
        for(int i = m; i < n; i++){
            mark_2[s2[i] - 'a']++;
            mark_2[s2[i-m] - 'a']--;
            if(compare(mark_1,mark_2)) return true;
        }
        return false;
    }
    bool compare(vector<int>& a, vector<int>& b){
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i]) return false;
        return true;
    }
};

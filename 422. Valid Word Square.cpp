/*
Given a sequence of words, check whether it forms a valid word square.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

Note:
The number of words given is at least 1 and does not exceed 500.
Word length will be at least 1 and does not exceed 500.
Each word contains only lowercase English alphabet a-z.
*/

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int m=words.size(),n=words[0].size();
        if(m!=n) return false;
        for(int i=0;i<m;i++){
            if(n<words[i].size()) return false;
            for(int j=i+1;j<n;j++){
                if((j<words[i].size() and i>=words[j].size()) or (i<words[j].size() and j >= words[i].size()) or words[i][j]!=words[j][i]) return false;
            }
        }
        return true;
    }
    
};

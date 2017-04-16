/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
*/
class Solution {
public:
    bool checkRecord(string s) {
        int i = 0, n = s.size();
        int count_A = 0,count_L = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != 'L') count_L = 0;
            else count_L++;
            if(s[i] == 'A') count_A++;
            if(count_A > 1 or count_L > 2) return false;
        }
        return true;
    }
};

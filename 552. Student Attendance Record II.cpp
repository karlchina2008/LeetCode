/*

Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:
Input: n = 2
Output: 8 
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times. 
Note: The value of n won't exceed 100,000.
*/

class Solution {
public:
    int checkRecord(int n) {
        if(n == 0) return 0;
        if(n == 1) return 3;
        unsigned long long m = pow(10,9)+7;
        unsigned long long P_B[n+1] = {0}, L_B[n+1] = {0}, LL_B[n+2] = {0};
        
        P_B[1] =  L_B[1] = 1;
        P_B[2] = 2;
        L_B[2] = 1;
        LL_B[2] = 1;
        
        for(int i = 3; i <= n; i++){
            
            P_B[i] = (P_B[i-1] + L_B[i-1] + LL_B[i-1])%m;
            L_B[i] = P_B[i-1]%m;
            LL_B[i] = P_B[i-2]%m;
        }
        
        unsigned long long temp = 2*(P_B[n-1] + L_B[n-1] + LL_B[n-1])+P_B[n] + L_B[n] + LL_B[n];
        int res = 0;
        for(int i = 1; i < n-1; i++){
            temp += ((P_B[i] + L_B[i] + LL_B[i])*(P_B[n-1-i] + L_B[n-1-i] + LL_B[n-1-i]))%m;
            temp %= m;
        }
        res = temp%m;
        return res;
    }
};

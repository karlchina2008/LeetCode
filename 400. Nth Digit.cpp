/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
*/
class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        long long sum=0,pos=1,i=1;
        while(sum<n){
            sum+=pos*9*i;
            if(sum==n) return 9;
            else if(sum>n){
                sum-=pos*9*i;
                sum=n-sum;
                string s;
                if(sum%i==0){s=to_string(pos+sum/i-1);return s.back()-'0';}
                else{s=to_string(pos+sum/i);return s[sum%i-1]-'0';}
            }
            pos*=10;i++;
        }
        return 0;
    }
};

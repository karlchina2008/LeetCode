/*
43. Multiply Strings  QuestionEditorial Solution  My Submissions
Total Accepted: 75195
Total Submissions: 300670
Difficulty: Medium
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res="";
        if(num1.size()==1){
            if(num1[0]=='0') return "0";
            res=num2;
            for(int i=0;i<(num1[0]-'0')-1;i++)
                res=add(res,num2);
            return res;
        }
        else if(num2.size()==1){
            if(num2[0]=='0') return "0";
            res=num1;
            for(int i=0;i<(num2[0]-'0'-1);i++)
                res=add(res,num1);
            return res;
        }
        else{
            string s1=to_string((num1.back()-'0')*(num2.back()-'0')),s2=multiply(num1.substr(0,num1.size()-1),num2.substr(0,num2.size()-1)),s3=multiply(num1.substr(num1.size()-1,1),num2.substr(0,num2.size()-1)),s4=multiply(num2.substr(num2.size()-1,1),num1.substr(0,num1.size()-1));
            s2+="00";s3+="0";s4+="0";
            return add(s1,add(add(s4,s3),s2));
        }
    }
    string add(string num1,string num2){
        string res="";
        int m=num1.size()-1,n=num2.size()-1,sign=0;
        while(m>=0 and n>=0){
            int temp=(num1[m--]-'0')+(num2[n--]-'0')+sign;
            res+=to_string(temp%10);
            sign=temp/10;
        }
        while(m>=0){
            int temp=(num1[m--]-'0')+sign;
            res+=to_string(temp%10);
            sign=temp/10;
        }
        while(n>=0){
            int temp=(num2[n--]-'0')+sign;
            res+=to_string(temp%10);
            sign=temp/10;
        }
        if(sign) res+="1";
        int left=0,right=res.size()-1;
        while(left<=right)
            swap(res[left++],res[right--]);
        return res;
    }
};

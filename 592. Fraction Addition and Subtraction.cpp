/*
Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.

Example 1:
Input:"-1/2+1/2"
Output: "0/1"
Example 2:
Input:"-1/2+1/2+1/3"
Output: "1/3"
Example 3:
Input:"1/3-1/2"
Output: "-1/6"
Example 4:
Input:"5/3+1/3"
Output: "2/1"
Note:
The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1,10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
*/

class Solution {
public:
    string fractionAddition(string expression) {
        int sign = 0, i = 0, n = expression.size();
        pair<int,int> fast;
        pair<int,int> res = {0,0};
        if(expression[0] == '-'){
            sign = -1;
            i++;
        }
        else
            sign = 1;
        while( i < n){
            int start = i;
            cout << "sign " << sign << endl;
            while(i < n and expression[i] != '/') i++;
            int nominator = stoi(expression.substr(start,i - start));
            //cout << "nominator " << nominator << endl;
            start = ++i;
            while(i < n and expression[i] != '-' and expression[i] != '+') i++;
            int len = i - start;
            int denominator = stoi(expression.substr(start,len));
            fast = make_pair(nominator,denominator);
            res= cal(res,fast,sign);
            
            if(i < n) sign = (expression[i] == '+')? 1 : -1;
            i++;
            
        }
        if(res.first < 0){
            return "-" + to_string(-res.first) + "/" + to_string(res.second);
        }
        else 
            return to_string(res.first) + "/" + to_string(res.second);
        
    }
    pair<int,int> cal(pair<int,int> a, pair<int,int> b,int sign){
        if(a.second == 0){
            if(sign > 0) return b;
            else return {-b.first,b.second};
        }
        int min_f = min_comm(a.second,b.second);
        pair<int,int> tmp;
        if(sign > 0){
            tmp = make_pair(a.first * (min_f/a.second) + b.first * (min_f/b.second),min_f);
        }
        else {
            tmp = make_pair(a.first * (min_f/a.second) - b.first * (min_f/b.second),min_f);
        }
        
        int max_f;
        if(tmp.first < 0){ max_f = max_comm(-tmp.first,tmp.second);}
        else {max_f = max_comm(tmp.first,tmp.second);}
        
        return make_pair(tmp.first/max_f,tmp.second/max_f);
    }
    int max_comm(int a, int b){//a >= b
        if( a < b) swap(a,b);
        if(a==0 or b == 0) return a;
        return max_comm(b, a % b);
    }
    int min_comm(int a ,int b){
        int comm = max_comm(a,b);
        return a*b/comm;
    }
};

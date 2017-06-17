/*
A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

Subscribe to see which companies asked this question.
*/

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        int digit = 0, lower = 0, upper = 0;
        vector<int> contin;
        int i = 0;
        while( i < s.size()){
            if(s[i] >= '0' and s[i] <= '9') digit++;
            else if(s[i] >= 'a' and s[i] <= 'z') lower++;
            else if(s[i] >='A' and s[i] <= 'Z') upper++;
            
            int j = i;
            while(i + 1 < s.size() and s[i+1] == s[i]) i++;
            if(i - j >= 2){
                contin.push_back(i - j + 1);
            }
            i++;
        }
        int sum = 0;
        for(int i = 0; i < contin.size(); i++){
            sum += contin[i];
        }
        sum -= 2*(contin.size());
        digit = digit > 0 ? 1 : 0;
        lower = lower > 0 ? 1 : 0;
        upper = upper > 0 ? 1 : 0;
        int left_over = 3 - (digit + lower + upper);
        if(n < 6){
            if(contin.empty() or contin[0] < 5) return max(left_over,6-n);
            else{
                return 2;   
            }
        }
        else if(n > 20){
            int start = n - 20, i = 0, res = 0;
            int res_0 = 0, res_1 = 0, res_2 = 0;
            for(int i = 0; i < contin.size(); i++){
                res += contin[i]/3;
            }
            //cout << res << endl;
            for(int i = 0; i < contin.size(); i++){
                switch(contin[i]%3) {
                    case 0: res_0++;break;
                    case 1: res_1++;break;
                    case 2: res_2++;break;
                }
            }
            //cout << res_0 <<" " << res_1 << " " << res_2 << endl;
            if(res_0 >= n - 20) return max(n-20 + left_over,res);
            else if(res_0 + 2*res_1 >= n-20){
                int temp = res + (n-20 - res_0 + 1)/2;
                return max(temp,n-20 + left_over);
            }
            else{
                int temp_left = n-20 - (res_0 + 2*res_1);
                int temp = res + res_1 + (temp_left)/3*2 + temp_left%3;
                return max(temp,n-20 + left_over);
            }
            
        }
        else{
            int res = 0;
            for(int i = 0; i < contin.size(); i++)
                res += contin[i]/3;
            return max(res,left_over);
        }
    }
};

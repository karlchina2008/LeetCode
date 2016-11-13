/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
*/

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        vector<int> ccount;
        int len = str.size();
        for(int i = 1; i < len; i++){
            if (str[i] == str[0] and len % i ==0)
                ccount.push_back(i);
        }
        for(auto num : ccount){
            string temp = str.substr(0,num);
            int flag = 1;
            for(int j = num; j <= len-num; j += num){
                if(str.substr(j,num) != temp) {flag = 0;break;}
            }
            if (flag) return true;
                
        }
        return false;
    }
};

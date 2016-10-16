/*
Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.
*/
class Solution {
public:
    string originalDigits(string s) {
        vector<pair<string,char>> mymap={{"zero",'0'},{"two",'2'},{"six",'6'},{"seven",'7'},{"five",'5'},{"four",'4'},{"three",'3'},{"one",'1'},{"eight",'8'},{"nine",'9'}};
        int ch[26]={0};
        for(auto c:s)
            ch[c-'a']++;
        string res;
        cout<<s.size()<<endl;
        for(auto str:mymap){
            string nums=str.first;
            char num=str.second;
            int mark=INT_MAX;
            for(int i=0;i<nums.size();i++){
                mark=min(ch[nums[i]-'a'],mark);
            }
            //cout<<mark<<endl;
            if(mark){
                for(int i=0;i<nums.size();i++){
                    ch[nums[i]-'a']-=mark;
                }
                res.resize(res.size()+mark,num);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};

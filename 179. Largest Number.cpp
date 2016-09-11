/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res;
        for(auto num:nums){
            res.push_back(to_string(num));
        }
        sort(res.begin(),res.end(),[](string a,string b){return (a+b)>(b+a);});
        if(res[0]=="0") return "0";
        string temp="";
        for(auto s:res)
            temp+=s;
        return temp;
    }
};

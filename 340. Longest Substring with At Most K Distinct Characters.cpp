/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> smap(128,0);
        int sum=0,left=0,res=0,count_size=0;
        for(int i=0;i<s.size();i++){
            if(!smap[s[i]-'0'])
                count_size++;
            smap[s[i]-'0']++;
            sum++;
            if(count_size<=k){
                res=max(res,sum);
            }
            else{
                int j=left;
                while(count_size>k){
                    if(!(--smap[s[j]-'0'])) count_size--;
                    sum--;
                    j++;
                }
                left=j;
            }
        }
        return res;
    }
};

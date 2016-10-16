/*
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=INT_MIN;
        int left=0,right=0;
        vector<int> mymap(26,0);
        int max_count=0,count=0;
        char mark=s[0];
        while(right<s.size()){
            while(right<s.size() and count-max_count<=k){
                max_count=max(++mymap[s[right]-'A'],max_count);
                mark=(max_count==mymap[s[right]-'A'])?s[right]:mark;
                count++;
                
                if((count-max_count) > k) {count--;--mymap[s[right]-'A'];break;}
                else right++;
            }

            res=max(res,count);
            --count;
            mymap[s[left]-'A']--;
            if(mark==s[left]) max_count--;
            left++;
        }
        return res;
    }
};

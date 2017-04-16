/*

Given a list of strings, you could assemble these strings together into a loop. Among all the possible loops, you need to find the lexicographically biggest string after cutting and making one breakpoint of the loop, which will make a looped string into a regular one.

So, to find the lexicographically biggest string, you need to experience two phases:

Assemble all the strings into a loop, where you can reverse some strings or not and connect them in the same order as given.
Cut and make one breakpoint in any place of the loop, which will make a looped string into a regular string starting from the character at the cutting point.
And your job is to find the lexicographically biggest one among all the regular strings.

Example:
Input: "abc", "xyz"
Output: "zyxcba"
Explanation: You can get the looped string "-abcxyz-", "-abczyx-", "-cbaxyz-", "-cbazyx-", 
where '-' represents the looped status. 
The answer string came from the third looped one, 
where you could cut from the middle and get "zyxcba".
Note:
The input strings will only contain lowercase letters.
The total length of all the strings will not over 1000.
*/
class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        vector<string> reverse_strs(n);
        vector<string> max_strs(n);
        for(int i = 0; i < n; i++){
            reverse_strs[i] = reverse(strs[i]);
            if( reverse_strs[i] > strs[i])  max_strs[i] = reverse_strs[i];
            else max_strs[i] = strs[i];
        }
        for(int i = 0; i < n; i++){
            int size = strs[i].size();
            string temp = "",temp_res = "";
            for(int k = (i+1)%n; k != i; k = (k+1)%n){
                temp += max_strs[k];
            }
            
            for(int j = 0; j < size; j++){
                string temp_1 = strs[i].substr(j,size-j) + temp + strs[i].substr(0,j);
                if(temp_res < temp_1) temp_res = temp_1;
                temp_1 = reverse_strs[i].substr(size-j-1,j+1) + temp + reverse_strs[i].substr(0,size-j-1);
                if(temp_res < temp_1) temp_res = temp_1;
            }
            if(res < temp_res) res = temp_res;
        }
        return res;
    }
    
    string reverse(string s){
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i++], s[j--]);
        }
        return s;
    }
    
};

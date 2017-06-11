/*

Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Example 1:
Input: 
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"
Example 2:
Input: 
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"

*/

class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        map<int,int> index;
        string left = "<b>",right = "</b>";
        for(int i = 0; i < dict.size(); i++){
            string substr = dict[i];
            size_t temp = 0;
            while(1){
                temp = s.find(substr,temp);
                if(temp != std::string::npos){
                    if(index.count(temp) == 0 or substr.size() > dict[index[temp]].size())
                        index[temp] = i;
                    temp++;
                }
                else break;
            }
        }
        vector<pair<int,int>> myvector(index.begin(),index.end());
        int n = myvector.size();
        int i = 0,prev = 0;
        string res = "";
        while( i < n){
            res += s.substr(prev,myvector[i].first - prev);
            int j = myvector[i].first;
            //cout << j << endl;
            prev = myvector[i].first + dict[myvector[i].second].size();
            while( i+1 < n and prev >= myvector[i+1].first){
                int temp = myvector[i+1].first + dict[myvector[i+1].second].size();
                prev = max(prev,temp);
                i++;
            }
            res += left + s.substr(j, prev - j) + right;
            i++;
        }
        if(prev < s.size())
            res += s.substr(prev,s.size() - prev);
        return res;
    }
};

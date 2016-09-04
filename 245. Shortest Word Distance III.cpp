/*
This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.
*/
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res_1=0,res_2=0,r=INT_MAX,flag_1=0,flag_2=0,s=INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1) {if(flag_1) s=min(s,i-res_1);flag_1=1;res_1=i;}
            if(words[i]==word2) {flag_2=1;res_2=i;}
            if(flag_1 and flag_2)
                r=min(r,abs(res_1-res_2));
        }
        return r==0?s:r;
    }
};

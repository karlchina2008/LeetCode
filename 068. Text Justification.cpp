/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i=0,left;
        vector<string> res;
        while(i<words.size()){
            int count=0,size=0;
            left=i;
            while(i<words.size()){
                size+=words[i].size();
                count++;
                if(size+count-1<=maxWidth)
                    i++;
                else{
                    int l=maxWidth-(size-words[i].size()+count-2);
                    string temp=transfer(words,left,i,l);
                    res.push_back(temp);
                    break;
                }
            }
        }
        string temp="";
        for(int t=left;t<i;t++){
            temp+=words[t];
            if(temp.size()<maxWidth)
                temp+=" ";
        }
        while(temp.size()<maxWidth) temp+=" ";
        res.push_back(temp);
        return res;
    }
    string transfer(vector<string> &words,int left,int i,int size){
        int de=i-left-1;
        string res="";
        if(de==0){
            res+=words[left];
            for(int t=0;t<size;t++)
                res+=" ";
            return res;
        }
        for(int t=left;t<left+size%de;t++){
            res+=words[t];
            for(int p=0;p<size/de+2;p++)
                res+=" ";
        }
        for(int t=left+size%de;t<i-1;t++){
            res+=words[t];
            for(int p=0;p<size/de+1;p++)
                res+=" ";
        }
        res+=words[i-1];
        return res;
    }
};

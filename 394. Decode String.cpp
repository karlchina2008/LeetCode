/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/
class Solution {
public:
    string decodeString(string s) {
        stack<string> mystack;
        int i=0,n=s.size();
        while(i<n){
            if(s[i]!=']') {
                if(s[i]=='['){
                    mystack.push(s.substr(i,1));i++;
                }
                else{
                    int count=0;
                    while(i+count<n and s[i+count]>='0' and s[i+count]<='9' and s[i+count]!=']' and s[i+count]!='[') count++;
                    while(i+count<n and s[i+count]>'9' and s[i+count]!=']' and s[i+count]!='[') count++;
                    mystack.push(s.substr(i,count));i+=count;
                }
            }
            else{
                string temp="",temp_res="";
                while(!mystack.empty() and mystack.top()!="["){
                    string temp_1=mystack.top();
                    reverse(temp_1);
                    temp+=temp_1;
                    mystack.pop();
                }
                reverse(temp);
                mystack.pop();
                int m=stoi(mystack.top());
                mystack.pop();
                for(int j=0;j<m;j++)
                    temp_res+=temp;
                mystack.push(temp_res);
                i++;
            }
        }
        string res="";
        while(!mystack.empty()){
            string temp=mystack.top();
            reverse(temp);
            res+=temp;
            mystack.pop();
        }
        reverse(res);
        return res;
    }
    void reverse(string &s){
        int left=0,right=s.size()-1;
        while(left<right){
            swap(s[left++],s[right--]);
        }
    }
};

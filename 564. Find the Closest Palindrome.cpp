/*

Given an integer n, find the closest integer (not including itself), which is a palindrome.

The 'closest' is defined as absolute difference minimized between two integers.

Example 1:
Input: "123"
Output: "121"
Note:
The input n is a positive integer represented by string, whose length will not exceed 18.
If there is a tie, return the smaller one as answer.
Subscribe to see which companies asked this question.

Show Tags
*/
class Solution {
public:
    string nearestPalindromic(string n) {
        int size = n.size();
        shared_ptr<vector<string>> mystr(new vector<string>());
        *mystr = range(n[(size-1)/2]);
        mystr->push_back(n.substr((size-1)/2,1));
        for(int i = (size-1)/2 - 1; i>=0; i--){
            shared_ptr<vector<string>> p(new vector<string>());
            for(auto x : (*mystr)){
                p->push_back(n[i]+ x);
            }
            vector<string> temp = range(n[i]);
            for(auto t:temp){
                if(t[0] > n[i])
                    p->push_back(t + string((size-1)/2 - i,'0'));
                else 
                    p->push_back(t + string((size-1)/2 - i,'9'));
            }
            swap(p,mystr);
        }
        long long cur = 0,diff = LLONG_MAX, tar = stoll(n);
        for(auto s : (*mystr)){
            //cout << s << endl;
            string temp = mirror(s,size%2);
            //cout << stoll(temp) << " " << diff << endl;
            long long temp_diff = abs(stoll(temp) - tar);
            //cout << stoll(temp) << " " << tar << " " << stoll(temp) - tar << endl;
            if(temp_diff != 0)
                if(diff > temp_diff or (diff == temp_diff and cur > stoll(temp))) {diff = temp_diff;cur = stoll(temp);}
        }
        long long temp;
        if(n[0] == '1'){
            temp = stoll("0" + string(size -1,'9'));
        }
        else if(n[0] == '9') temp = stoll(string("1" + string(size -1,'0') + "1"));
        //cout << temp << endl;
        
        if(diff > abs(tar - temp) or (diff == abs(tar - temp) and cur > temp)) cur = temp;
        return to_string(cur);
    }
    vector<string> range(char c){
        vector<string> res;
        if(c == '0'){
            res.push_back("1");
        }
        else if(c == '9'){
            res.push_back("8");
        }
        else {
            res.push_back(to_string(c + 1 - '0'));
            res.push_back(to_string(c -1 - '0'));
        }
        return res;
    }
    string mirror(string& s, int mark){
        string res = s;
        if(mark){
            for(int i = s.size() - 2; i >= 0; i--){
                res.push_back(s[i]);
            }
        }
        else{
            for(int i = s.size()-1; i >=0; i--){
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

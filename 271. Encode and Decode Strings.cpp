/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
*/
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res="";
        //cout<<strs.size()<<endl;
        for(auto str:strs){
            res+="(";
            res+=to_string(str.size());
            res+=")";
            res+=str;
            //cout<<res<<endl;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int begin=1;
        while(begin<s.size()){
            string temp="";
            while(begin<s.size() and s[begin]!=')'){
                temp+=s[begin];
                begin++;
            }
            begin++;
            //cout<<temp<<endl;
            int len=stoi(temp);
            //cout<<len<<" "<<begin<<endl;
            //string str;
            res.push_back(s.substr(begin,len));
            //cout<<res.back()<<endl;
            begin+=len+1;
        }
        return res;
    }
};

/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language.
Derive the order of letters in this language.
*/
class Solution {
public:
    //typedef pair<unordered_set<char>,unordered_set<char>> cc;
    string alienOrder(vector<string>& words) {
        vector<unordered_set<int>> graph(26);
        for(int i=0;i<words[0].size();i++)
            graph[words[0][i]-'a'].insert(words[0][i]-'a');
        for(int i=0;i<words.size()-1;i++){
            int i1=0,i2=0;
            //cout<<i<<endl;
            while(i1<words[i].size() and i2<words[i+1].size()){
                graph[words[i+1][i2]-'a'].insert(words[i+1][i2]-'a');
                if(words[i][i1]!=words[i+1][i2]){
                    graph[words[i][i1]-'a'].insert(words[i+1][i2]-'a');
                    break;
                }
                i1++;i2++;
            }
            while(i2<words[i+1].size()){
                graph[words[i+1][i2]-'a'].insert(words[i+1][i2]-'a');
                i2++;
            }
        }
        string res="";
        int count;
        for(int i=0;i<26;i++)
            if(!graph[i].empty()) count++;
        for(int i=0;i<26;i++){
            //cout<<(i+'a')<<" "<<graph[i]<<endl;
            help(graph,res,i);
        }
        if(res.size()>count) return "";
        int left=0,right=res.size()-1;
        while(left<right){
            swap(res[left++],res[right--]);
        }
        return res;
    }
        void help(vector<unordered_set<int>> &graph,string &res,int pos){
            if(pos==graph.size() or graph[pos].empty()) return;
            unordered_set<int> temp=graph[pos];
            for(auto it=temp.begin();it!=temp.end();it++){
                if(*it!=pos){
                    graph[pos].erase(*it);
                    help(graph,res,*it);
                }
            }
            char t=pos+'a';
            res+=t;
            graph[pos].erase(pos);
        }
};

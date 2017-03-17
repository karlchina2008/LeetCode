/*
Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesn't make the word shorter, then keep it as original.
*/
class TrieNode {
public:
    // Initialize your data structure here.
    unordered_map<char,TrieNode*> Children;
    int end,count,child;
    TrieNode() {
        end=0;count = 0;child = 0;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();// copy, assignment and destructor have to be redesigned!! 
    }
    Trie(const Trie& curtrie){ // user-defined copy constructor;
        copy(curtrie.root,root);
    }
    Trie& operator=(const Trie& curtrie){ // user-defined assignment constructor;
        if(curtrie.root != root){ // handle self-assignment;
            destroy(root);
            copy(curtrie.root,root);
        } 
        return *this;    
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp=root;
        for(auto c:word){
            if( !temp->Children.empty() and temp->Children.count(c)) 
            {   
                temp=temp->Children[c];
                temp->count++;
                continue;
                
            }
            else{
                temp->Children[c] = new TrieNode();// memory has to be released manually;
                temp->child ++;
                temp=temp->Children[c];
                temp->count++;
            }
        }
        temp->end=1;
    }
    void remove(string word){ // make sure that this word exist;
        TrieNode* temp = root;
        for(auto c:word){
                temp = temp->Children[c];
                temp->count--;
        }
    }
    // Returns if some prefix of the word is in the trie.
    int searchunique(string word) {
        TrieNode* temp=root;
        int res = 0;
        for(auto c:word){
            if(!temp->Children.empty() and temp->Children.count(c) and temp->Children[c]->count == 1) 
                return ++res;
            temp=temp->Children[c];
            ++res;
            //cout << temp->count << endl;
        }
        return word.size();
    }
    ~Trie(){
        destroy(root);
    }
private:
    TrieNode* root;
    void destroy(TrieNode* cur){
        if(cur == NULL) return;
        if(cur->child == 0) delete cur;// if no child, then safe to delete;
        else
            for(auto ch:cur->Children){
                {destroy(ch.second);cur->child--;}
            }
    }
    void copy(TrieNode* root, TrieNode* new_root){
        new_root->end = root->end;
        new_root->count = root->count;
        new_root->child = root->child;
        for(auto ch:root->Children){
            new_root->Children[ch.first] = new TrieNode();
            copy(root->Children[ch.first],new_root->Children[ch.first]);
        }
    }
};

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<string> res(n);
        vector<pair<string,int>> new_dict(n);
        for(int i = 0; i < n; i++){
            new_dict[i] = {dict[i],i};
        }
        sort(new_dict.begin(),new_dict.end(),[](pair<string,int> a,pair<string,int> b){if((a.first.size() == (b.first.size()))){
            if(a.first[0] == b.first[0]) return a.first.back() < b.first.back();
            else return a.first[0] < b.first[0];
        }
            return a.first.size() < b.first.size();
        });
        int i = 0;
        Trie mytrie = Trie();
        while ( i < n){
            int m = new_dict[i].first.size();
            char start = new_dict[i].first[0], end = new_dict[i].first.back();
            mytrie.insert(new_dict[i].first);
            int j = i;
            i++;
            while( i < n and (new_dict[i].first.size()) == m and new_dict[i].first[0] == start and new_dict[i].first.back() == end) {
                mytrie.insert(new_dict[i].first);
                i++;
            }
            for(int t = j; t < i; t++){
                string temp = new_dict[t].first;
                int u = mytrie.searchunique(temp),k = temp.size();
                //cout << temp << " " <<u << endl;
                if(u <= k-3){
                    string res_temp = temp.substr(0,u)+to_string(k - u -1) + temp.back();
                    res[new_dict[t].second] = res_temp;
                }
                else
                    res[new_dict[t].second] = temp;
            }
            for(int t = j; t < i; t++) mytrie.remove(new_dict[t].first);
        }
        return res;
    }
};

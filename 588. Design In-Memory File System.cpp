/*
Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.

Example:
Input: 
["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
[[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
Output:
[null,[],null,null,["a"],"hello"]
Explanation:
filesystem
*/

struct node{
    string name;
    map<string,node*> next;
    map<string,string> content;
    node(string name_): name(name_){}
};
class FileSystem {
public:
    FileSystem() {
        root = new node("/");
    }
    
    vector<string> ls(string path) {
        int i = 1, n = path.size();
        node * temp = root;
        vector<string> res;
        while( i < n){
            int start = i;
            while( i < n and path[i] != '/') i++;
            string s = path.substr(start,i - start);
            i++;
            if((temp->next).count(s) > 0){
                temp = temp->next[s];
            }
            else if( (temp->content).count(s) > 0){
                res.push_back(s);
                return res;
            }
        }
        auto it_d = temp->next.begin();
        auto it_f = temp->content.begin();
        while(it_d != temp->next.end() and it_f != temp->content.end()){
            if(it_d->first < it_f->first){
                res.push_back(it_d->first);
                it_d++;
            }
            else{
                res.push_back(it_f->first);
                it_f++;
            }
        }
        while(it_d != temp->next.end()){
            res.push_back(it_d->first);
            it_d++;
        }
        while(it_f != temp->content.end()){
            res.push_back(it_f->first);
            it_f++;
        }
        return res;
    }
    
    void mkdir(string path) {
        int i = 1, n = path.size();
        node * temp = root;
        while( i < n){
            int start = i;
            while( i < n and path[i] != '/') i++;
            string s = path.substr(start,i - start);
            i++;
            if(temp->next.count(s) > 0){
                temp = temp->next[s];
            }
            else{
                temp->next[s] = new node(s);
                temp = temp->next[s];
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
        int i = 1, n = filePath.size();
        node * temp = root;
        while( i < n){
            int start = i;
            while( i < n and filePath[i] != '/') i++;
            string s = filePath.substr(start,i - start);
            i++;
            if(temp->next.count(s) > 0){
                temp = temp->next[s];
            }
            else if(temp->content.count(s) > 0){
                temp->content[s] += content;
                return;
            }
            else {
                temp->content[s] = content;
                return;
            }
        }
    }
    
    string readContentFromFile(string filePath) {
        int i = 1, n = filePath.size();
        node * temp = root;
        string res = "";
        while( i < n){
            int start = i;
            while( i < n and filePath[i] != '/') i++;
            string s = filePath.substr(start,i - start);
            i++;
            if(temp->next.count(s) > 0){
                temp = temp->next[s];
            }
            else if(temp->content.count(s) > 0){
                res = temp->content[s];
                return res;
            }
        }
        return res;
    }
private:
    node* root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

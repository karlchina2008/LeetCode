/*
Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.

The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.

next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
hasNext() - Judge whether there is any letter needs to be uncompressed.

Example:

StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");

iterator.next(); // return 'L'
iterator.next(); // return 'e'
iterator.next(); // return 'e'
iterator.next(); // return 't'
iterator.next(); // return 'C'
iterator.next(); // return 'o'
iterator.next(); // return 'd'
iterator.hasNext(); // return true
iterator.next(); // return 'e'
iterator.hasNext(); // return false
iterator.next(); // return ' '
*/
class StringIterator {
public:
    StringIterator(string compressedString) {
        cur = 0;
        in = 0;
        s = "";
        int n = compressedString.size();
        int i = 0;
        //cout << n << endl;
        while(i < n){
            s.push_back(compressedString[i]);
            i++;
            int j = i;
            while(i < n and compressedString[i] <= '9') i++;
            int num = stoi(compressedString.substr(j,i - j));
            //cout << compressedString[i] << endl;
            index.push_back(num);
        }
        //cout << s << endl;
        
        size = s.size();
    }
    char next() {
        if(!hasNext()) return ' ';
        char res = s[in];
        cur++;
        if(cur >= index[in]){
            cur = 0;
            in++;
        }
        return res;
    }
    
    bool hasNext() {
        return in < size;
    }
private:
    int cur,size,in;
    string s;
    vector<int> index;
};

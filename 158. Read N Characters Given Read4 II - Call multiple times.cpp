/*
The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
*/
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution():sum(0){}
    int read(char *buf, int n) {
        int count=0,temp=4;
        while(count<n and temp==4){
            temp=read4(buf);
            buf+=temp;
            count+=temp;
        }
        int cur=(count>n)?n:count;
        sum+=cur;
        return sum;
    }
    private:
        int sum;
        char buffer[4];
};

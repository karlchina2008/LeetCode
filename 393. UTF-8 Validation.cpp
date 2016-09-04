/*
A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:

For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
Given an array of integers representing the data, return whether it is a valid utf-8 encoding.
*/
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n=data.size(),t=1<<7,i=0;
        while(i<n){
            if(data[i]<t){i++;}
            else{
                //cout<<i<<endl;
                int sign=0,count=0;
                //if(data[i]^t<(1<<6)) return false;
                for(int j=2;j<=4;j++){
                    int s=((1<<j)-1)<<(8-j);
                    //cout<<(s^data[i])<<endl;
                    if((s^data[i])<(1<<(7-j))){
                        sign=j;break;
                    }
                    else count++;
                }
                if(count==3) return false;
                for(int j=i+1;j<i+sign;j++){
                    //cout<<(t^data[j])<<endl;
                    if(j>=n or (t^data[j])>=(1<<6)) return false;
                }
                i+=sign;
            }
        }
        return true;
    }
};

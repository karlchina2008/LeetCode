/*
An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6
*/
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left=y,right=y,up=x,down=x,n=image.size(),m=image[0].size();
        image[x][y]=' ';
        help(image,left,right,up,down,x,y,n,m);
        return (right-left+1)*(down-up+1);
        
    }
    void help(vector<vector<char>> &image,int &left,int &right,int &up,int &down,int x,int y,int &n,int &m){
        //if(x+1>=n or x-1<0 or y+1>=m or y-1<0) return;
        if(x+1<n and image[x+1][y]=='1'){
            down=max(x+1,down);
            //cout<<"down"<<down<<endl;
            image[x+1][y]='0';
            help(image,left,right,up,down,x+1,y,n,m);
            //image[x+1][y]='1';
        }
        if(x-1>=0 and image[x-1][y]=='1'){
            up=min(x-1,up);
            //cout<<"up"<<up<<endl;
            image[x-1][y]='0';
            help(image,left,right,up,down,x-1,y,n,m);
            //image[x-1][y]='1';
        }
        if(y+1<m and image[x][y+1]=='1'){
            right=max(y+1,right);
            //cout<<"right"<<right<<endl;
            image[x][y+1]='0';
            help(image,left,right,up,down,x,y+1,n,m);
            //image[x][y+1]='1';
        }
        if(y-1>=0 and image[x][y-1]=='1'){
            left=min(y-1,left);
            //cout<<"left"<<left<<endl;
            image[x][y-1]='0';
            help(image,left,right,up,down,x,y-1,n,m);
            //image[x][y-1]='1';
        }
    }
};

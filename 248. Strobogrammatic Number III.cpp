/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

For example,
Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.

Note:
Because the range might be a large number, the low and high numbers are represented as string.
*/
class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int l=low.size(),h=high.size();
        if(l>h) return 0;
        string gram="01689";
        unordered_map<char,char> mymap={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        int sum=0;
        for(int i=l+1;i<h;i++){
            if(i%2==0){
                sum+=4*pow(5,i/2-1);
            }
            else
                sum+=3*4*pow(5,i/2-1);
        }
        int res_1,res_2;
        res_1=helpfind_1(low,gram,0,l,0,mymap);
        res_2=helpfind_1(high,gram,0,h,0,mymap);
        int lo=0,hi=high.size()-1,res=1;
        while(lo<=hi)
            if(mymap.find(high[hi])==mymap.end() or mymap.find(high[lo])==mymap.end() or high[hi--]!=mymap[high[lo++]]) {res=0;break;}
        if(l==h){
            return max(0,sum+res_1-res_2+res);
        }
        else{
            int temp;
            if(h%2==0) temp=4*pow(5,h/2-1);
            else temp=3*4*pow(5,h/2-1);
            
            return sum+res_1-res_2+res+temp;
        }
    }
    
    int helpfind_1(string &low,string &gram,int begin,int l,int count,unordered_map<char,char> &mymap){
        if(l>1 and begin>=l/2) return 0;
        if(l==1){
            string temp="018";
            auto lo=lower_bound(temp.begin(),temp.end(),low[begin]);
            return 3-(lo-temp.begin());
        }
        
        int sum=0,pos;
        auto it=lower_bound(gram.begin(),gram.end(),low[begin]);
        pos=it-gram.begin();
        if(*it==low[begin]) count++;
        if(l%2==0 and count==l/2){
            sum=4-pos;
            int i=1,res=1;
            while(i<=l/2){
                if(low[i+l/2-1]>mymap[low[l/2-i]]) {res=0;break;}
                i++;
            } 
            return sum+res;
        }
        if(l%2==1 and count==l/2 and l>1){
            sum=3*(4-pos);
            string temp="018";
            auto lo=lower_bound(temp.begin(),temp.end(),low[begin+1]);
            if(*lo==low[begin+1]){
                sum+=2-(lo-temp.begin());
                int i=1,res=1;
                while(i<=l/2){
                    if(low[i+l/2]>mymap[low[l/2-i]]) {res=0;break;}
                    i++;
                }
                sum+=res;
            }
            else
                sum+=3-(lo-temp.begin());
            return sum;
        }
        if(*it==low[begin]){
            if(l%2==0)
                sum=helpfind_1(low,gram,begin+1,l,count,mymap)+(4-pos)*pow(5,l/2-begin-1);
            else
                sum=helpfind_1(low,gram,begin+1,l,count,mymap)+(4-pos)*pow(5,l/2-begin-1)*3;
        }
        else
            if(l%2==0)
                sum=(5-pos)*pow(5,l/2-begin-1);
            else
                sum=(5-pos)*pow(5,l/2-begin-1)*3;
        return sum;
    }
};

/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.


For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
*/
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        //int all_hour=1<<4-1,all_mi=1<<6-1;
        vector<string> res;
        for(int i=0;i<=num;i++){
            vector<string> hour,mi;
            if(i<4 and num-i<6){
                helpfind(0,0,i,0,hour,0);
                helpfind(0,0,num-i,0,mi,1);
                for(auto s1:hour)
                    for(auto s2:mi)
                        res.push_back(s1+":"+s2);
            }
        }
        return res;
    }
    void helpfind(int cur_pos,int count,int sum,int temp, vector<string> &res,int label){
        if(count==sum){
            if(label==0){
                if(temp<12) res.push_back(to_string(temp));
            }
            else{
                if(temp<60){
                    if(temp<10) res.push_back("0"+to_string(temp));
                    else res.push_back(to_string(temp));
                }
            }
        }
        int digit=(label==0)?4:6;
        for(int i=cur_pos;i<digit;i++){
            helpfind(i+1,count+1,sum,temp^(1<<i),res,label);
        }
    }
};

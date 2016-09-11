/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> euqations, vector<double>& values, vector<pair<string, string>> query . where equations.size() == values.size(),the values are positive. this represents the equations.return vector<double>. . 
The example above: equations = [ ["a", "b"], ["b", "c"] ]. values = [2.0, 3.0]. queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].

The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> query) {
        unordered_map<string,int> hash;
        int count=0;
        for(auto eq:equations){
            if(hash.count(eq.first)==0) hash[eq.first]=count++;
            if(hash.count(eq.second)==0) hash[eq.second]=count++;
        }
        //cout<<count<<endl;
        vector<int> find(count,0),size(count,0);
        vector<vector<double>> res(count,vector<double>(count,1.0));
        for(int i=0;i<count;i++){
            find[i]=i;
        }
        for(int i=0;i<values.size();i++){
            res[hash[equations[i].first]][hash[equations[i].second]]=values[i];
            //res[hash[equations[i].second]][hash[equations[i].first]]=1/values[i];
        }
        for(auto eq:equations){
            int temp_1=hash[eq.first],temp_2=hash[eq.second];
            double r_1=1,r_2=1;
            while(temp_1!=find[temp_1]){r_1*=res[find[temp_1]][temp_1]*res[find[find[temp_1]]][find[temp_1]];res[find[find[temp_1]]][temp_1]=r_1;find[temp_1]=find[find[temp_1]];temp_1=find[temp_1];}
            while(temp_2!=find[temp_2]){r_2*=res[find[temp_2]][temp_2]*res[find[find[temp_2]]][find[temp_2]];res[find[find[temp_2]]][temp_2]=r_2;find[temp_2]=find[find[temp_2]];temp_2=find[temp_2];}
            if(temp_1!=temp_2){
                if(size[temp_1]>=size[temp_2]){
                    find[temp_2]=temp_1;
                    res[temp_1][temp_2]=r_1*res[hash[eq.first]][hash[eq.second]]/r_2;
                    size[temp_1]+=size[temp_2];
                }
                else{
                    find[temp_1]=temp_2;
                    res[temp_2][temp_1]=r_2/r_1/res[hash[eq.first]][hash[eq.second]];
                    size[temp_2]+=size[temp_1];
                }
            }
        }
        vector<double> result;
        for(auto q:query){
            if(hash.count(q.first)==0 or hash.count(q.second)==0) result.push_back(-1.0);
            else{
                double r_1=1,r_2=1;
                int temp_1=hash[q.first],temp_2=hash[q.second];
                while(find[temp_1]!=temp_1){
                    r_1*=res[find[temp_1]][temp_1];
                    temp_1=find[temp_1];
                    
                }
                while(find[temp_2]!=temp_2){
                    r_2*=res[find[temp_2]][temp_2];
                    temp_2=find[temp_2];
                    
                }
                if(temp_1!=temp_2) result.push_back(-1.0);
                else result.push_back(r_2/r_1);
            }
        }
        return result;
    }
};

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int,int>>& people) {
        auto cmp=[](pair<int,int> a,pair<int,int> b){return (a.first==b.first)?(a.second<=b.second):(a.first>b.first);};
        sort(people.begin(),people.end(),cmp);
        vector<pair<int,int>> res;
        int len=people.size();
        for(int i=0;i<len;i++){
            if(people[i].second<i){
                res.insert(res.begin()+people[i].second,people[i]);
            }
            else res.push_back(people[i]);
        }
        return res;
    }
};

/*
A frog is crossing a river. The river is divided into x units and at each unit there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog is able to cross the river by landing on the last stone. Initially, the frog is on the first stone and assume the first jump must be 1 unit.

If the frog has just jumped k units, then its next jump must be either k - 1, k, or k + 1 units. Note that the frog can only jump in the forward direction.

Note:

The number of stones is ≥ 2 and is < 1,100.
Each stone's position will be a non-negative integer < 231.
The first stone's position is always 0.
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<unordered_set<long long>> record(n,unordered_set<long long>());
        if(stones[1]!=1) return false;
        else if(stones.size()==2) return true;
        for(int i=2;i<=3;i++){
            if(i==stones.back()) return true;
            auto it=lower_bound(stones.begin()+2,stones.end(),i);
            //if(*it==stones.back()) return true;
            if(*it==i) record[it-stones.begin()].insert(i-1);
        }
        for(int i=2;i<n;i++){
            if(record[i].size()!=0){
                for(auto jump:record[i]){
                    cout<<jump<<endl;
                    for(int j=jump-1;j<=jump+1;j++){
                        if(j>0){
                            if(stones[i]+j==stones.back()) return true;
                            auto it=lower_bound(stones.begin()+i+1,stones.end(),stones[i]+j);
                            if(*it==stones[i]+j) record[it-stones.begin()].insert(j);
                        }
                    }
                }
            }
        }
        return false;
    }
};

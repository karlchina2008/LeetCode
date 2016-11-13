/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        vector<int> small(n+1,0);
        int temp = INT_MAX;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            temp = temp > num ? num : temp;
            small[i+1] = temp;
            //cout << temp<<endl;
        }
        set<int> myset;
        myset.insert(-nums.back());
        for(int i = n-2; i >= 1; i--){
            auto it = myset.upper_bound(-nums[i]);
            if(it != myset.end()){
                cout <<(*it) <<" " << small[i] << endl;
                int num = -(*it);
                if( num > small[i]) return true;
            }
            myset.insert(-nums[i]);
        }
        return false;
        
    }
};

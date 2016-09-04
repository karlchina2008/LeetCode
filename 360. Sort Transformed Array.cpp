/*
Given a sorted array of integers nums and integer values a, b and c. Apply a function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)
*/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        if(a==0){
            if(b>0){
                for(int i=0;i<nums.size();i++)
                    res.push_back(b*nums[i]+c);
            }
            else{
                for(int i=nums.size()-1;i>=0;i--)
                    res.push_back(b*nums[i]+c);
            }
            return res;
        }
        int mid=floor(-(float(b)/2/float(a)));
        auto it=upper_bound(nums.begin(),nums.end(),mid);
        vector<int> left,right;
        for(auto temp=nums.begin();temp!=it;temp++){
            int x=(*temp);
            left.push_back(a*x*x+b*x+c);
        }
        for(auto temp=it;temp!=nums.end();temp++){
            int x=(*temp);
            right.push_back(a*x*x+b*x+c);
        }
        if(a<0)
            reverse(right.begin(),right.end());//not necessary;
        else
            reverse(left.begin(),left.end());
        int i=0,j=0;
        while(i<left.size() and j<right.size()){
            if((left[i]<=right[j])) res.push_back(left[i++]);
            else res.push_back(right[j++]);
            //cout<<res.back()<<endl;
        }
        while(i<left.size()) res.push_back(left[i++]);
        while(j<right.size()) res.push_back(right[j++]);
        return res;
        
    }
};

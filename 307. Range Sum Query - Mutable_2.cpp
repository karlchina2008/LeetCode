/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
*/
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int n=1;
        m=nums.size();
        _nums.resize(m,0);
        while(n<m){
            n*=2;
        }
        sum.resize(n+1,0);
        for(int i=0;i<m;i++){
            update(i,nums[i]);
        }
        _nums=nums;
    }

    void update(int i, int val) {
        val=val-_nums[i];
        _nums[i]+=val;
        i++;
        while(i<=m){
            sum[i]+=val;
            i+=i&(-i);
        }
    }

    int sumRange(int i, int j) {
        j++;
        int sum_1=0,sum_2=0;
        while(i>0){
            sum_1+=sum[i];
            i-=i&(-i);
        }
        while(j>0){
            sum_2+=sum[j];
            j-=j&(-j);
        }
        return sum_2-sum_1;
    }
private:
    vector<int> sum;
    vector<int> _nums;
    int m;
};

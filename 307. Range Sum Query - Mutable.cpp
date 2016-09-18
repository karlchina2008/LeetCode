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
        n=1;
        int m=nums.size();
        while(n<m) n*=2;
        sum.resize(2*n+1,0);
        for(int i=0;i<m;i++) update(i,nums[i]);
    }
    
    void update(int i, int val) {
        i+=n;
        int dif=val-sum[i];
        sum[i]=val;
        while(i>0){
            sum[i/2]+=dif;
            i/=2;
        }
        
    }

    int sumRange(int i, int j) {
        return helpsum(1,n,i+1,j+1,1);
    }
    int helpsum(int start,int end,int left,int right,int root){
        if(start>right or end<left) return 0;
        else if(start==left and end==right) return sum[root];
        else if((start+end)/2<left) return helpsum((start+end)/2+1,end,left,right,root*2+1);
        else if((start+end)/2>right) return helpsum(start,(start+end)/2,left,right,root*2);
        else return helpsum(start,(start+end)/2,left,(start+end)/2,root*2)+helpsum((start+end)/2+1,end,(start+end)/2+1,right,root*2+1);
    }
private:
    vector<int> sum;
    vector<int> _nums;
    int n;
};

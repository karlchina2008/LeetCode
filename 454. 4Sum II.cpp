/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        vector<int> AB(n*n,0),CD(n*n,0);
        for(int i=0; i < n; i++)
            for(int j = 0; j < n; j++){
                AB[i*n+j] = A[i]+B[j];
                CD[i*n+j] = C[i]+D[j];
            }
        sort(AB.begin(),AB.end());
        sort(CD.begin(),CD.end());
        //cout <<"here"<<endl;
        int i = 0, res =0;
        while (i < n*n){
            //cout<< i << endl;
            int j = i;
            while (j< n*n-1 and AB[j+1] == AB[j]) ++j;
            int target = -AB[i];
            int dif = distance(lower_bound(CD.begin(),CD.end(),target),upper_bound(CD.begin(),CD.end(),target));
            res += dif*(j-i+1);
            i = j+1;
        }
        return res;
        
    }
};

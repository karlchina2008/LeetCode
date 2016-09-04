/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.
*/
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size(),m=n>0?A[0].size():0,k=m>0?B[0].size():0;
        vector<vector<int>> _A(n,vector<int>()),_B(k,vector<int>()),C(n,vector<int>(k,0));
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                if(A[i][j]) temp.push_back(j);
            }
            _A[i]=temp;
        }
        for(int i=0;i<k;i++){
            vector<int> temp;
            for(int j=0;j<m;j++)
                if(B[j][i]) temp.push_back(j);
            _B[i]=temp;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<k;j++){
                int a=0,b=0,sum=0;
                while(a<_A[i].size() and b<_B[j].size()){
                    if(_A[i][a]<_B[j][b]) a++;
                    else if(_A[i][a]>_B[j][b]) b++;
                    else{
                        sum+=A[i][_A[i][a++]]*B[_B[j][b++]][j];
                    }
                }
                C[i][j]=sum;
            }
        return C;
    }
};

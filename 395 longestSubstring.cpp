class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        int res[n+1][26];
        memset(res,0,sizeof(res));
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++)
                res[i+1][j]=res[i][j];
            res[i+1][s[i]-'a']++;
        }
        int count,fin=0,sign_2;
        for(int i=0;i<=n-k;i++){
            for(int j=n;j>=i+k;j--){
                count=0;sign_2=0;
                for(int l=0;l<26;l++){
                    if(res[j][l]==0) continue;
                    if(res[j][l]-res[i][l]<k and res[j][l]!=res[i][l]){sign_2=1;break;}
                    else count+=res[j][l]-res[i][l];
                }
                if(sign_2==0){
                    fin=max(fin,count);
                    break;
                }
            }
        }
        return fin;
    }
};

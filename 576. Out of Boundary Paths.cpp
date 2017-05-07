/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.
*/

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if( N == 0) return 0;
        unsigned long long M = pow(10,9) + 7;
        long long dp[m+2][n+2][N+1] = {{{0}}};
        //vector<vector<vector<int>>> dp(m+2,vector<vector<int>>(n+2,vector<int>(N+1,0)));
        //memset(dp, 0, sizeof(dp[0][0][0]) * (m+2) * (n+2)*(N+1));
        memset(dp, 0, sizeof(dp));
        for(int i1 = 1; i1 <= m; i1++)
            for(int j1 = 1; j1 <= n ;j1++){
                if(i1 == 1) dp[i1][j1][1]++;
                if(i1 == m) dp[i1][j1][1]++;
                if(j1 == 1) dp[i1][j1][1]++;
                if(j1 == n) dp[i1][j1][1]++;
            }
        //cout << dp[2][1][1] <<"here" << endl;
        for(int k1 = 2; k1 <= N; k1++){
            for(int i1 = 1; i1 <= m; i1++)
                for(int j1 = 1; j1 <= n; j1++){
                    dp[i1][j1][k1] = dp[i1+1][j1][k1-1]%M + dp[i1-1][j1][k1-1]%M + dp[i1][j1+1][k1-1]%M + dp[i1][j1-1][k1-1]%M;
                }
        }
        long long res = 0;
        for(int k1 = 1; k1 <= N ;k1++){
            res += dp[i+1][j+1][k1]%M;
            res %= M;
        }
        return res;
    }
};

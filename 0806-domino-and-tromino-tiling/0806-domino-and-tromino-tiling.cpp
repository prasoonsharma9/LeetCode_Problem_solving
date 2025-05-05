class Solution {
public:
    int m = 1000000007;
    // int f(int n, vector<int>& dp){
    //     if(n == 1 || n == 2) return n;
    //     if(n == 3) return 5;

    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = (2*f(n-1, dp) % m + f(n-3, dp) % m) % m;
    // }

    int numTilings(int n) {
        if(n == 1 || n == 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (2*dp[i-1] % m + dp[i-3] % m) % m;
        }
        return dp[n];
    }
};
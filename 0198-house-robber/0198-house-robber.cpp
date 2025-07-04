class Solution {
public:
//MEMOIZATION (TOP - DOWN) APPROACH
    // int f(int idx, vector<int>& nums, vector<int>& dp){
    //     if(idx == 0) return nums[idx];
    //     if(idx < 0) return 0;
    //     if(dp[idx] != -1) return dp[idx];

    //     int pick = nums[idx] + f(idx-2, nums, dp);
    //     int notPick = 0 + f(idx-1, nums, dp);

    //     return dp[idx] = max(pick, notPick); 
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp (n,-1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){ 
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];
            int no = 0 + dp[i-1];

            dp[i] = max(pick, no);
        }
        return dp[n-1];
    }
};
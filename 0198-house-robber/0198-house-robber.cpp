class Solution {
public:
    int tryRob(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if(idx >= n){
            return 0;
        }

        if(dp[idx] != -1) return dp[idx];

        // Pick current house
        int pick = nums[idx] + tryRob(idx + 2, nums, dp);

        // Skip current house
        int skip = tryRob(idx + 1, nums, dp);

        // Store the max of both choices
        return dp[idx] = max(pick, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return tryRob(0, nums, dp);
    }
};

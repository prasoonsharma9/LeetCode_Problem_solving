class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        long long maxi = nums[0];
        long long mini = nums[0];

        for(int i=1; i<n; i++){
            long long curr = nums[i];
            if(curr < 0) swap(maxi, mini);
            maxi = max(curr, maxi*curr);
            mini = min(curr, mini*curr);

            result = max(result, static_cast<int>(maxi));
        }
        return result;
    }
};
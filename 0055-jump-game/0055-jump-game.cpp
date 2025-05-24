class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        for(int i=0; i<n; i++){
            int temp = nums[i];
            if(i > maxIdx) return false;
            else if(i >= n-1) return true;
            maxIdx = max(maxIdx, i+nums[i]);
        }
        return true;
    }
};
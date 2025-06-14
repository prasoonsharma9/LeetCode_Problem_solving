class Solution {
public:
    void powerSet(int ind, vector<int>& temp, vector<int>& nums,vector<vector<int>>& ans, int n){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        powerSet(ind+1, temp, nums, ans, n);
        temp.pop_back();
        powerSet(ind+1, temp, nums, ans, n);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        powerSet(0, temp, nums, ans, n);
        return ans;
    }
};
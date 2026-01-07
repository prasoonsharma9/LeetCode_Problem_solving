class Solution {
public:
    void powerSet(int idx, vector<int> &ans, vector<vector<int>> &result, vector<int>& candidates, int sum, int target){
        int n = candidates.size();
        if(sum == target){
            result.push_back(ans);
            return;
        }
        if(idx == n || sum > target){
            return;
        }

        ans.push_back(candidates[idx]);
        powerSet(idx, ans, result, candidates, sum+candidates[idx], target);

        ans.pop_back();
        powerSet(idx+1, ans, result, candidates, sum, target);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> result;
        powerSet(0, ans, result, candidates, 0, target);
        return result;
    }
};

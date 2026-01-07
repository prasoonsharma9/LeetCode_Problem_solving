class Solution {
public:

    void powerset(int idx, vector<int> &candidates, vector<int> &ans, vector<vector<int>> &result, int target, int n, int sum){
        if(sum == target){
            result.push_back(ans);
            return;
        }
        if(idx == n || sum > target) return;
        ans.push_back(candidates[idx]);
        powerset(idx, candidates, ans, result, target, n, sum + candidates[idx]);
        ans.pop_back();
        powerset(idx+1, candidates, ans, result, target, n, sum);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ans;
        vector<vector<int>> result;
        int idx = 0;
        powerset(idx, candidates,ans,result, target, n, 0);
        return result;
    }
};
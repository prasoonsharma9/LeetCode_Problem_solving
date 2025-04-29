class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        if(n==1) ans.push_back(-1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<=i+n-1; j++){
                int idx = j%n;
                if(nums[idx] > nums[i]){
                    ans.push_back(nums[idx]);
                    break;
                }
                if(idx == (i+n-1)%n) ans.push_back(-1);
            }
        }
        return ans;
    }
};
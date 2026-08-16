class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        vector<int> unique;
        for(auto x: mp) unique.push_back(x.first);

        sort(unique.begin(), unique.end(), [&](int a, int b){
            if(mp[a] == mp[b]) return a > b;

            return mp[a] < mp[b];
        });

        vector<int> ans;
        for(auto x: unique){
            for(int i=0; i<mp[x]; i++){
                ans.push_back(x);
            }
        }

        return ans;
    }
};
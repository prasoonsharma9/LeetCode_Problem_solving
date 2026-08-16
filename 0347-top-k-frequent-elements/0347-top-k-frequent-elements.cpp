class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
            greater<pair<int, int>>
        >minH;

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto i=mp.begin(); i!=mp.end(); i++){
            minH.push({i->second, i->first});
            if(minH.size() > k) minH.pop();
        }

        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;

    }
};
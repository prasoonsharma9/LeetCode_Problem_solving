class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mpp;
        stack<int> st;
        vector<int> ans;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        for(auto i: nums1){
            ans.push_back(mpp[i]);
        }

        return ans;
    }
};
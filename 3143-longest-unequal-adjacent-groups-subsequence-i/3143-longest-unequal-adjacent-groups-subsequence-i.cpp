class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans;
        int lastGrp = -1;
        for(int i=0; i<n; i++){
            if(groups[i] != lastGrp){
                ans.push_back(words[i]);
                lastGrp = groups[i];
            }
        }
        return ans;
    }
};
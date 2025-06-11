class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        int maxi = 0;
        int mini = n;
        vector<int>mpp(26);
        for(auto c: s) mpp[c-'a']++;
        for(int i=0; i<26; i++){
            if(mpp[i] % 2 != 0) maxi = max(maxi, mpp[i]);
            if(mpp[i] % 2 == 0 && mpp[i] > 0) mini =  min(mini, mpp[i]);
        }
        return maxi - mini;
    }
};
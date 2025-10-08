class Solution {
    int binary(vector<int>& potions, long long power, long long success){
        int l = 0, h = potions.size()-1;
        int ind = -1;
        int mid = l + (h - l)/2;
        while (l <= h){
            if(1LL * power * potions[mid] >= success){
                ind = mid;
                h = mid - 1;
            }
            else l = mid + 1;

            mid = l + (h - l)/2;
        }
        return ind;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();

        for(int i=0; i<n; i++){
            int ind = binary(potions, spells[i], success);
            if (ind != -1) ans.push_back(m - ind);
            else ans.push_back(0);
        }

        return ans;
    }
};
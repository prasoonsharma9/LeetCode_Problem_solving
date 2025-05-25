class Solution {
public:
    static bool sortBySecond(vector<int>& a, vector<int>&b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), sortBySecond);

        int cnt = 1;
        int prevComplete = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= prevComplete){
                cnt++;
                prevComplete = intervals[i][1];
            }
        }

        return n - cnt;
    }
};
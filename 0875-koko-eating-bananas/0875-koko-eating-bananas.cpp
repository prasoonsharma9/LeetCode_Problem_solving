class Solution {
private:
    long long time(vector<int>& piles, int banana){
        long long totalTime = 0;
        for(int i=0; i<piles.size(); i++){
            totalTime += (piles[i] + banana - 1) / banana;
        }
        return totalTime;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = e;
        while(s <= e){
            int mid = (s + e)/2;
            long long reqTime = time(piles, mid);

            if(reqTime <= h){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

        }
        return ans;
    }
};
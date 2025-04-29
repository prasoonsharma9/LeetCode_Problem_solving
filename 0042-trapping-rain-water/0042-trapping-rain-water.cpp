class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> preMax(n);
        preMax[0] = height[0];
        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], height[i]);
        }

        vector<int> suffMax(n);
        suffMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffMax[i] = max(suffMax[i+1], height[i]);
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            int leftMax = preMax[i];
            int rightMax = suffMax[i];
            if(height[i] < leftMax && height[i] < rightMax){
                int waterLevel = min(leftMax, rightMax);
                if(waterLevel > height[i]){
                    cnt += waterLevel - height[i];
                }
            }
        }
        return cnt;
    }
};
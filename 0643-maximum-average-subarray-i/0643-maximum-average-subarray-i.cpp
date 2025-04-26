class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int sum = 0;
        int maxSum = INT_MIN;
        while(j < n){
            sum += nums[j];
            while(j-i+1 >= k){
                maxSum = max(sum, maxSum);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        double avg = (double)maxSum / k;
        return avg;
    }
};
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int f = nums[0];
        int s = nums[1];
        int t = nums[2];
        if(f == s && s == t && t == f) return "equilateral";
        else if((f + s) > t && (s + t) > f && (f + t) > s){
            if(f == s || s == t || f == t) return "isosceles";
            else return "scalene";
        }

        return "none";
    }
};
class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSE = findNSE(heights);
        vector<int> PSE = findPSE(heights);
        int maxi = 0;

        for(int i=0; i<n; i++){
            maxi = max(maxi, heights[i] * (NSE[i] - PSE[i] - 1));
        }
        return maxi;
    }
};
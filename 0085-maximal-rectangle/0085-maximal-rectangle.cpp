class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPSE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int hist(vector<int>& arr){
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i] * (nse[i] - pse[i] -1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea  = 0;

        vector<vector<int>> pSum(n, vector<int>(m));
        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){
                if(matrix[i][j] == '1') sum += 1;
                else sum = 0;
                pSum[i][j] = sum;
            }
        }

        for(int i=0; i<n; i++){
            maxArea = max(maxArea, hist(pSum[i]));
        }
        return maxArea;
    }
};
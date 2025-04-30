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

    vector<int> findPSEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;  
        long long total = 0;
        vector<int> NSE = findNSE(arr);
        vector<int> PSEE = findPSEE(arr);

        for(int i=0; i<n; i++){
            long long left = i - PSEE[i];
            long long right = NSE[i] - i;
            total = (total + (arr[i] * left % mod * right % mod)) % mod;
        }
        return total;
    }
};


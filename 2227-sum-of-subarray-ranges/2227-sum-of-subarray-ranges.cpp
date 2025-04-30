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

    long long smallest(vector<int>& arr){
        int n = arr.size();
        long long total = 0;
        vector<int> PSEE = findPSEE(arr);
        vector<int> NSE = findNSE(arr);
        for(int i=0; i<n; i++){
            long long left = i - PSEE[i];
            long long right = NSE[i] - i;
            total += 1LL * arr[i] * left * right;
        }
        return total;
    }

    vector<int> findNGE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findPGEE(vector<int>& arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    long long largest(vector<int>& arr){
        int n = arr.size();
        long long total = 0;
        vector<int> PGEE = findPGEE(arr);
        vector<int> NGE = findNGE(arr);
        for(int i=0; i<n; i++){
            long long left = i - PGEE[i];
            long long right = NGE[i] - i;
            total += 1LL * arr[i] * left * right;
        }
        return total;
    }

    long long subArrayRanges(vector<int>& arr) {
        return largest(arr) - smallest(arr);
    }
};

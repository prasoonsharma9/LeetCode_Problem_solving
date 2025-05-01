class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid){
        int pillsUsed = 0;
        multiset<int> st(workers.begin(), workers.begin() + mid);

        for(int i=mid-1; i>=0; i--){
            int req = tasks[i];
            auto it = prev(st.end());

            if(*it >= req) st.erase(it);
            else if(pillsUsed >= pills) return false;
            else{
                auto weakestWorkerID = st.lower_bound(req - strength);
                if(weakestWorkerID != st.end()){
                    st.erase(weakestWorkerID);
                    pillsUsed++;
                }
                else return false;
            }
        }
        return true;
    }


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size();
        int m = workers.size();

        sort(tasks.begin(), tasks.end());
        sort(workers.rbegin(), workers.rend());
        int result = 0;

        int l = 0;
        int r = min(n, m);

        while(l <= r){
            int mid = l + (r-l) / 2;
            if(check(tasks, workers, pills, strength, mid)){
                result = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return result;
    }
};
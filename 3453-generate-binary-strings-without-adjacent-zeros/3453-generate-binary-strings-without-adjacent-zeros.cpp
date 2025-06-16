class Solution {
public:
    void func(int n, int len, vector<string>& ans, string &temp){
        if(len == n){
            ans.push_back(temp); 
            return;
        }

        if(temp.empty() || temp.back() != '0'){
            temp += '0';
            func(n, len+1, ans, temp);
            temp.pop_back();
        }

        temp += '1';
        func(n, len+1, ans, temp);
        temp.pop_back();
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        int len = 0;
        string temp = "";
        func(n, len, ans, temp);
        return ans;
    }
};
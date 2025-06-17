class Solution {
public:
    void func(int open, int close, vector<string>& ans, string& temp){
        if(open == 0 && close == 0){
            ans.push_back(temp);
            return;
        }

        if(open == close){
            temp.push_back('(');
            func(open-1, close, ans, temp);
            temp.pop_back();
        }
        else if(open == 0){
            temp.push_back(')');
            func(open, close-1, ans, temp);
            temp.pop_back();
        }
        else{
            temp.push_back('(');
            func(open-1, close, ans, temp);
            temp.pop_back();

            temp.push_back(')');
            func(open, close-1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";
        func(n, n, ans, temp);
        return ans;
    }
};
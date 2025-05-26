class Solution {
public:
    int minNumberOfFrogs(string s) {
        int n = s.size();
        int c=0, r=0, o=0, a=0, k=0;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'c'){
                c++;
                cnt = max(cnt, c-k);
            }
            else if(s[i] == 'r') r++;
            else if(s[i] == 'o') o++;
            else if(s[i] == 'a') a++;
            else if(s[i] == 'k') k++;
            if(c >= r && r >= o && o >= a && a >= k ) continue;
            else return -1;
        }
        return (c == r && r == o && o == a && a == k ) ? cnt : -1;
    }
};
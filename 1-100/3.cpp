class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[200] = {0};
        int ans = 0, cnt = 0;
        int l = 0, r = 0;
        while(l < s.length() && r < s.length()) {
            if(vis[s[r]] == 0) {
                ans = max(r - l + 1, ans);
                vis[s[r]]++;
                r++;
            } else {
                while(vis[s[r]] > 0) {
                    vis[s[l]]--;
                    l++;
                }
            }
        }
         
        return ans;
    }
};
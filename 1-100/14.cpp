class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = INT_MAX, len = strs.size();
        if(len < 1) return "";
        else if(len < 2) return strs[0];
        int l1 = strs[0].length();
        for(int i = 1; i < len; ++i) {
            int l = strs[i].length(), tmp = -1;
            for(int j = 0; j < l1 && j < l; j++) {
                if(strs[i][j] == strs[0][j]) tmp = j;
                else break;
            }
            pos = min(pos, tmp);
        }
        if(pos == INT_MAX) return "";
        return string(&strs[0][0], &strs[0][pos + 1]);
    }
};
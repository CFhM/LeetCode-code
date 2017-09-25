class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long xx = (long long)x;
        long long tmp = 0LL;
        while(x) {
            tmp = tmp * 10LL + x % 10;
            x /= 10;
        }
        return xx == tmp;
    }
};
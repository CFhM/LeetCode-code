#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define MP make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (a); i > b; --i)
#define mem(a, b) memset((a), (b), sizeof((a)))
#define dbg(x) cout << #x << "=" << x << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 5;
// head
class Solution {
public:
    string longestPalindrome(string s) {
		string str = "$#";
		int len = s.length();
		for(int i = 0; i < len; i++) str += s[i], str += "#";
		int mx = 0, id = 0, l = str.length();
		int st = 0, ans = 0;
		vector<int> vec;
		vec.resize(l);
		for(int i = 0; i < l; i++) {
			vec[i] = (mx > i ? min(vec[2 * id - i], mx - i) : 1);
			while(str[i + vec[i]] == str[i - vec[i]]) vec[i]++;
			if(i + vec[i] > mx) {
				mx = vec[i] + i;
				id = i;
			}
			if(ans < vec[i] - 1) {
				ans = vec[i] - 1;
				st = i / 2 - (ans + 1) / 2;
			}
		}
		// dbg(st);
		// dbg(ans);
		string ret(&s[st], &s[st + ans]);
		// for(int i = 0; i < ans; i++) ret k+= s[st + i];
		return ret;
		// string ret = string(s[st], s[st + ans]);
		// return ret;
    }
};
int main() {
	cin.sync_with_stdio(false);
	Solution sol;
	string s;
	while(cin >> s) {
		cout << sol.longestPalindrome(s) << endl;
	}
	return 0;
}
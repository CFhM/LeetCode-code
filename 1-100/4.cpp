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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size();
		if(len1 > len2) {
			swap(nums1, nums2);	
			// nums1.swap(nums2);	
			swap(len1, len2);
		}
		
		int l = 0, r = 2 * len1, len = len1 + len2;
		while(l <= r) {
			int mid = l + (r - l) / 2, mid2 = len - mid;

			int L1 = mid == 0 ? INT_MIN : nums1[(mid - 1) / 2];
			int L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
			int R1 = mid == 2 * len1 ? INT_MAX : nums1[mid / 2];
			int R2 = mid2 == 2 * len2 ? INT_MAX : nums2[mid2 / 2];

			if(L1 > R2) r = mid - 1;
			else if(L2 > R1) l = mid + 1;
			else return 0.5 * (min(R1, R2) + max(L1, L2));
		}
    }
};

vi vec1, vec2;
int main() {
	int n, m;
		Solution sol;
	while(~scanf("%d", &n)) {
		vec1.clear(); vec2.clear();
		rep(i, 0, n) {
			scanf("%d", &m);
			vec1.pb(m);
		}
		scanf("%d", &m);
		rep(i, 0, m) {
			scanf("%d", &n);
			vec2.pb(n);
		}

		printf("%f\n", sol.findMedianSortedArrays(vec1, vec2));
	}
}
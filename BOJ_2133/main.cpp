#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
vl dp;

int solve(ll x) {
	for (auto i = 4; i <= x; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (auto j = i - 4; 0 <= j; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	if (1 == n % 2) {
		cout << 0;
		return 0;
	}

	dp = vl(n + 1, -1);
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;

	cout << solve(n);

	return 0;
}
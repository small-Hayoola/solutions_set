#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;

// from atcoder dp contest

long long dp[100010];

int main () {
	int n , w;
	int k , v;

	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> k >> v;

		for (int j = w - k; j >= 0; j--) {
			dp[j + k] = max(dp[j + k], dp[j] + v);
		}

	}
	long long top = 0;
	for (int i = 1; i <= w; i++)
		top = max(top, dp[i]);

	cout << top;
}
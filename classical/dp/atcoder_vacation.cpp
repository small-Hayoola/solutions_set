#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
int activities[100001][3];
int dp[100001][3];

int main() {
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> activities[i][0] >> activities[i][1] >> activities[i][2];
	}

	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	for(int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][1],dp[i - 1][2]) + activities[i][0];
		dp[i][1] = max(dp[i - 1][0],dp[i - 1][2]) + activities[i][1];
		dp[i][2] = max(dp[i - 1][0],dp[i - 1][1]) + activities[i][2];
	}

	cout << max(dp[N][0],max(dp[N][1],dp[N][2]));
}
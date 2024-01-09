#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int dp_here[1000000][2];
int dp[1000000][3];
int n,m;
 
int main() {
	cin >> n >> m;
 
	dp_here[1][0] = 1;
	dp_here[1][1] = 1;
	dp_here[0][1] = 1;
	dp_here[0][0] = 1;
 
	for(int i = 2; i <= min(n , m); i++) {
		dp_here[i][0] = (dp_here[i - 2][1] + dp_here[i - 1][0]) % MOD;
		dp_here[i][1] = (dp_here[i - 2][0] + dp_here[i - 1][1]) % MOD;
	}
 
	dp[1][0] = 2;
	dp[1][1] = ((dp_here[min(n,m)][0] + dp_here[min(n,m)][1]) % MOD - 2) % MOD;
 
	for(int i = 2; i <= max(n , m); i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][1] = dp[i - 1][1] % MOD;
		dp[i][2] = dp[i - 1][0] % MOD;
	}
 
	cout << ((dp[max(n , m)][0] + dp[max(n , m)][1]) % MOD + dp[max(n , m)][2]) % MOD;
}
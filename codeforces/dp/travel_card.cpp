#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
 
const int size = (1e5 + 3);
int n;
int t[int(1e5 + 3)];
int dp[int(1e5 + 3)];
 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)	
		cin >> t[i];
 
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + 20;
		dp[i] = min(dp[i], dp[(upper_bound(t, t+n, t[i] - 90) - t) - 1] + 50);
		dp[i] = min(dp[i], dp[(upper_bound(t, t+n, t[i] - 1440) - t) - 1] + 120);
 
		cout << dp[i] - dp[i - 1] << endl;
	}
}
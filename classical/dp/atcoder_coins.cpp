#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
	
int n;
long double p[int(3000)];
long double dp[int(3000)][int(3000)];
	
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	cin >> n;

	for (int i = 1; i <= n; i++) 
		cin >> p[i];

	dp[0][0] = 1;

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= j; i++) {
			if(j == 0) {	
				dp[j][i] = dp[j - 1][i] * (1 - p[j]);
			} else {
				dp[j][i] = dp[j - 1][i - 1] * p[j] + dp[j - 1][i] * (1 - p[j]);				
			}
		}
	}

	long double ans = 0;
	for(int i = n/2 + 1; i <= n; i++) 
		ans += dp[n][i];

	cout << setprecision(10) << ans;
}
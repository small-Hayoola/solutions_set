#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
 
const int size = 1e3 + 3;
const int MOD = 1e9 + 7;
int n;
int maxs[size],dp[size], dp_mins[size];
 
string s;
 
 
int main() {
	cin >> n >> s;
 
	for (int i = 0; i < 26; i++) 
		cin >> maxs[i];
	
	dp[0] = 1;
	int max_size = 1;
	
	for (int i = 1; i <= n; i++) {
		int min_size = 1e9;
 
		int min_subs = i;
		for (int j = 1; j <= i; j++) {
			min_size = min(min_size, maxs[s[i - j] - 'a']);
			if (j <= min_size) {
 
				dp[i] = (dp[i] + dp[i - j]) % MOD;
 
				if (dp[i - j]) {
					max_size = max(max_size, j);
					min_subs = min(min_subs, dp_mins[i - j] + 1);
				}
			}
		}
		dp_mins[i] = min_subs;
	}
 
	
	cout << dp[n] << "\n" << min(max_size, n) << "\n" << dp_mins[n];
}
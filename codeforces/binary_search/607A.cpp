#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
pair <int, int> bombs[int(2e5 + 54)];
int dp[int(2e5 + 54)];


int find(int x) {
	int l = 0;
	int r = n;

	while(l < r) {
		int mid = (r + l) / 2;
		if(x <= bombs[mid].first) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return l;
}

int main() 
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> bombs[i].first >> bombs[i].second;


	sort(bombs, bombs+n);
	int out = 0;

	dp[0] = 0;
	int best = 0;

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = dp[find(max(bombs[i - 1].first - bombs[i - 1].second, 0))] + 1;
		best = max(dp[i], best);
	}

	cout << n - best;

}
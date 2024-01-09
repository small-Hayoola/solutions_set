#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
	
int n,k;
int a[102];
int dp[int(2e5 + 4)];
string ans[2] = {"First","Second"};

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int j = 1; j <= k; j++)
		for(int i = 0; i < n; i++) {
			if(j - a[i] >= 0 && dp[j - a[i]] == 0) {
				dp[j] = 1;
			}
		}

	cout << ans[1 - dp[k]];
}
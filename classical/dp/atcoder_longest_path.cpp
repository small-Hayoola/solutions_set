#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;


vector <int> tos[100002];
int dp[100002];
int n,m;

int main_top = 0;


int find_max_path(int i) {
	if (dp[i] != 0) {
		return dp[i];
	}

	int top_path_from_i = 0;
	for (int c: tos[i]) {
		top_path_from_i = max(top_path_from_i, find_max_path(c) + 1);
	}

	dp[i] = top_path_from_i;
	return dp[i];
}

void read() {
	cin >> n >> m;

	int w,v = 0;
	for (int i = 0; i < m; i++) {
		cin >> v >> w;
		tos[w].push_back(v);
	}
}

void solve() {
	for (int i = 1; i <= n; i++) {
		main_top = max(main_top, find_max_path(i));
	}
}


int main () {
	read();
	solve();

	cout << main_top;
}
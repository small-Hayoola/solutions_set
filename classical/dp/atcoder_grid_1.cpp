#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;
	
int h,w;
ll grid[1001][1001];
ll dp[1001][1001];
const ll MOD = 1e9 + 7;
	
int main() {
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		string content;
		cin >> content;
		for (int j = 0; j < w; j++){
			if (content[j] == '.') {
				grid[i][j + 1] = 1;
			} else {
				grid[i][j + 1] = 0;
			}
		}
	}

	dp[1][1] = 1;
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w; j++) {
			if(i * j != 1) 
				dp[i][j] = ((grid[i-1][j] * dp[i - 1][j]) + (grid[i][j-1] * dp[i][j - 1])) % MOD;
		}
	}
	
	cout << dp[h][w];
}
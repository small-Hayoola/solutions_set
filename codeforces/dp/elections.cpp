#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
 
int N;
const int size = 1e5 + 3;
vector <int> edge[size];
vector <int> problems[size];
vector <int> passage;
bool mark[size]; 
int dp[size];
 
void dfs(int u, int par) {
	mark[u] = true;
 
	for (int c: edge[u]) 
		if (!mark[c]) {
			dfs(c,u);
			dp[u] += dp[c];
		}
 
 
	for(int i: problems[u]) {
		if(i == par) {
 
		} else {
			if(dp[i] == 0) {
				dp[u] += 1;
				passage.push_back(i);
			}
		}
	}
}
 
void read() {
	cin >> N;
	for(int i = 1; i < N; i++) {
		int v,u,is_prob;
		cin >> v >> u >> is_prob;
 
		edge[v].push_back(u); 
		edge[u].push_back(v);
 
		if(is_prob == 2) {
			problems[u].push_back(v);
			problems[v].push_back(u);
		}
	}
}
 
void solve() {
	dfs(1,-1);
}
 
void out() {
	cout << dp[1] << endl;
	for(int c: passage) {
		cout << c << " ";
	}
}
 
int main() {
	read();
	solve();
	out();
}
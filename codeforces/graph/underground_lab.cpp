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
 
// from https://codeforces.com/contest/781/problem/C

const int size = 2e5 + 4;
vector <int> edge[size];
int mark[size];
vector <int> passage;
int n,m,k;
 
void dfs(int u) {
	mark[u] = true;
	passage.push_back(u);
 
	for(int c: edge[u]) {
		if(!mark[c]) {
			dfs(c);
			passage.push_back(u);
		}
	}
}
 
int main() {
	cin >> n >> m >> k;
	int u,v = 0;
 
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
 
	dfs(u);
 
	int movage = 0;
 
	int tops = ((2*n + (k - 1)) / k);
 
 
	if(n == 1) {
		cout << 1 << " " << 1;
		exit(0);
	}
 
	for(int i = 0; i < k; i++) {
		int amount = min(int(passage.size()), tops);
		if(amount == 0) {
			cout << endl;
			cout << "1" << " " << u;
		} else {
			cout << "\n" << amount;			
		}
 
		for (int j = 0; j < amount; j++) {
			cout << " " << passage.back();
			passage.pop_back();
		}
	}
 
}
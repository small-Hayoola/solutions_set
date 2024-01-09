#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
 
const ll MOD = 1000000007;
int k;
int c[int(1e4 + 3)];
ll comb[1005][1005];
ll main_ans = 1;
 
ll __fact(ll given) {
	ll amount = 1;
	for(int i = 1; i <= given; i++) 
		amount = (amount * i + MOD) % MOD;
	return amount;
}
 
void read() {
	cin >> k;
	for(int i = 0; i < k; i++)
		cin >> c[i];
}
 
void make() {
	// comb 
	comb[0][0] = 1;
	for(int i = 1; i <= 1004; i++) {
		comb[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
 
}
 
void solve() {
	int sum = c[0];
	for(int i = 1; i < k; i++) {
		sum += c[i];
		main_ans = (main_ans * comb[sum - 1][c[i] - 1]) % MOD;
	}
}
 
void print() {
	cout << main_ans;
}
 
int main() {
	read();
	make();
	solve();
	print();
}
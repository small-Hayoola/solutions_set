#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
 
int n,x;
int ps[int(2e5 + 4)];
 
int main() {
	cin >> n >> x;
 
	for (int i = 0; i < n; ++i)
	{
		cin >> ps[i];
	}
 
	sort(ps, ps+n);
 
	int l = 0;
	int out = 0;
	int r = n - 1;
 
	while(r > l) {
		if(ps[r] + ps[l] <= x) {
			out++;
			l++;
			r--;
		} else {
			out++;
			r--;
		}
	}
 
	if(l == r) 
		out++;
 
	cout << out << endl;
}
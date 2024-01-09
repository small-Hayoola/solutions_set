#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
 
int N = 2e5;
int n;
int number[int(2e5)];
 
void solve() {
 
	cin >> n;
 
	for(int i = 0; i < n; i++) {
		cin >> number[i];
	}
	
 
	sort(number, number+n);
	ll l = 0;
	ll r = 1e9 + 1;
 
	while (r - l >= 1){
        ll mid = (l + r) / 2;
 
        ll cnt = 0;
        ll last = 0;
 
        for(int i = 0; i < n; i++){
            if ((number[i] - number[last]) > mid * 2){
                last = i; 
                cnt++;
            }
        }
        cnt += (last != n);
 
        if (cnt > 3) {
        	l = mid + 1;
        } else { 
        	r = mid;
        }
    }
 
	cout << l << endl;
 
}
 
int main() {
	int t;
	cin >> t;
 
	while(t--) {
		solve();
	}
}
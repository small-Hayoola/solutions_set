#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

const int size = 1e5 + 3;
ll a[size];
int n, k;

int main() {
	int q;
	cin >> q;
	while (q--) {
		cin >> n >> k;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a, a+n);
		ll out = a[0];

		if(k >= 3) {
			out = 0;
		} else if (k == 1) {
			for (int i = 1; i < n; i++)
				out = min(out, a[i] - a[i - 1]);
		} else if (k == 2) {
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++) {
					ll here = a[j] - a[i];
					out = min(out, here);

					int search = lower_bound(a, a+n, here) - a;

					out = min(abs(a[search] - here), out);

					if (search > 0)
						out = min(abs(a[search - 1] - here), out);
				}
		}
		
		cout << out << endl;
	}
}
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
 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int board[54][54];
bool mark[54][54];
int n;

const ll INF = 1e9 + 4;

int important = 1;

int start_x;
int start_y;
int end_x;
int end_y;

int out = INF;

bool __val(int x, int y) {
	if(x < n && y < n && x >= 0 && y >= 0)
		return true;
	return false;
}

void __clear() {
	for(int i = 0; i < 54; i++) {
		for(int j = 0; j < 54; j++) {
			mark[i][j] = false;
		}
	}
}

void dfs(int x,int y) {
	mark[x][y] = true;


	for (int i = 0; i < 4; ++i)
	{
		int x_here = x + dx[i]; 
		int y_here = y + dy[i];

		if(__val(x_here, y_here) && !mark[x_here][y_here] && ((important & (1 << (board[x_here][y_here]))) == (1 << (board[x_here][y_here])))) {
			dfs(x_here,y_here);
		}
	}
}


void solve() {
	out = INF;
	cin >> n;

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			cin >> board[i][j];

	cin >> start_x >> start_y;
	cin >> end_x >> end_y;

	for(int i = 0; i < (1 << 11); i++) {
		important = i;
		__clear();

		if((important & (1 << (board[start_x][start_y]))) == (1 << (board[start_x][start_y])))
			dfs(start_x,start_y);

		if(mark[end_x][end_y] == true) {
			out = min(out, __builtin_popcount(important));
		}
	}

	cout << out << endl;
}


int main() {
	int t;
	cin >> t;

	while(t--)
		solve();
}
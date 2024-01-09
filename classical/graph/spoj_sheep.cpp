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

const int N = 260;
int n,m;
bool mark[N][N];
char place[N][N];
int sheep = 0;
int wolfs = 0;

int changed_wolfs = 0;
int changed_sheep = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


bool __val(int x,int y) {
	return (((x >= 0) && (x < n)) && ((y >= 0) && (y < m)));
}


void dfs(int x,int y) {
	if(!mark[x][y]) {
		if(place[x][y] == 'k') {
			changed_sheep++;
		} else if (place[x][y] == 'v') {
			changed_wolfs++;
		}
	}

	mark[x][y] = true;


	for (int i = 0; i < 4; i++) {
		int x_here = x + dx[i];
		int y_here = y + dy[i];

		if(__val(x_here, y_here) && !(mark[x_here][y_here]) && place[x_here][y_here] != '#') 
			dfs(x_here, y_here);
	}
}


int main() {
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		string inp;
		cin >> inp;

		for(int c = 0; c < m; c++) {
			place[i][c] = inp[c];

			if(place[i][c] == 'k') {
				sheep++;
			} else if (place[i][c] == 'v') {
				wolfs++;
			}
		}
		
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!mark[i][j]) {
				changed_sheep = 0;
				changed_wolfs = 0;
				dfs(i,j);

				if(changed_sheep > changed_wolfs) {
						wolfs -= changed_wolfs;
				} else {
						sheep -= changed_sheep;
				}
			}	
		}
	}

	cout << sheep << " " << wolfs;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;

int n,m;
char board[1002][1002];
bool mark[1002][1002];
int comp[1002][1002];
int comp_size[1000000];
int comp_count = 0;
int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0, 0, 1, -1};
string ans[1002];

int __val(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs (int x, int y, int power_comp) {
    mark[x][y] = true;
    comp[x][y] = power_comp;
    comp_size[power_comp]++;

    for (int i = 0; i < 4; i++) {
        int x_here = x + dx[i];
        int y_here = y + dy[i];
        if (__val(x_here, y_here) && !mark[x_here][y_here] && board[x_here][y_here] == '.') 
            dfs(x_here,y_here,power_comp);
    }
}

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!mark[i][j] && board[i][j] == '.') {
                comp_count++;
                dfs(i,j,comp_count);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                cout << ".";
            } else {
                vector <int> comps_here;
                comps_here.clear();
                int ans_block = 1;
                for (int c = 0; c < 4; c++) {
                    int x_here = i + dx[c];
                    int y_here = j + dy[c];
                    if (__val(x_here, y_here) && board[x_here][y_here] == '.') 
                        comps_here.push_back(comp[x_here][y_here]);
                }
                sort(comps_here.begin(), comps_here.end());
                
                for (int u = 1; u < comps_here.size(); u++) {
                    if (comps_here[u] == comps_here[u - 1]) {
                        comps_here[u - 1] = -1;
                    }
                }
                for (int k: comps_here) {
                    if (!(k == -1))
                        ans_block = (ans_block + comp_size[k]) % 10;
                }
                cout << (ans_block) % 10;

            
            }
        }
        cout << endl;
    }
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string whole;
        cin >> whole;
        for (int j = 0; j < m; j++) 
            board[i][j] = whole[j];
    }
}

int main() {
    read(), solve();
}
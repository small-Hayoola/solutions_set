#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
vector <int> graph[int(2e5 + 54)];
int color_v[2][int(2e5 + 54)];
bool mark[int(2e5 + 54)];
bool ok = true;

void dfs(int u, int color) {
    mark[u] = true;

    if (graph[u].size() > 2) {
        ok = false;
        return;
    }

    for (int c: graph[u]) {
        if(!mark[])
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 1)
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
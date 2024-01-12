#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

const int size = 2e5 + 4;
ll n, sum, mx;
ll val[size] ,sz[size],ans[size];
vector<int> graph[size];

void dfs(int u, int par) {
    if (par != -1)
        ans[u] = ans[par] - sz[u] + sum - sz[u];
    for (int c: graph[u]) 
        if (c != par) 
            dfs(c, u);
}
void dfs_ans(int u, int par, int size) {
    ans[1] += (size + 1) * val[u];
    sz[u] = val[u];
    for (int c: graph[u]) 
        if(c != par) {
            dfs_ans(c, u, (size + 1));
            sz[u] += sz[c];
        }
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        sum += val[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs_ans(1,-1,-1);
    dfs(1,-1);
    for (int i = 1; i <= n; i++) 
        mx = max(ans[i],mx);
    cout << mx;
}
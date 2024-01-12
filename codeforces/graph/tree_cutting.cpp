#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
vector <int> graph[int(3e5 + 54)];
int color[int(3e5 + 54)];
bool mark[int(3e5 + 54)];
int ans,main_red,main_blue = 0;

pair <int, int> dfs(int u, int par) {
    mark[u] = true;
    int red_count = 0;
    int blue_count = 0;

    for (int c: graph[u]) {
        if(!mark[c] && c != par) {
            pair <int, int> result = dfs(c, u);
            if (result.first == 0 && result.second == main_blue) {
                ans++;
            } else if (result.first == main_red && result.second == 0) {
                ans++;
            }
            red_count += result.first;
            blue_count += result.second;
        }
    }

    if (color[u] == 1) {
        return make_pair(red_count + 1, blue_count);    
    } else if (color[u] == 2) {
        return make_pair(red_count, blue_count + 1);
    } else {
        return make_pair(red_count, blue_count);
    }
}

void solve() {
    dfs(1, 0);
    cout << ans;
}

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
        if(color[i] == 1) {
            main_red++;
        } else if (color[i] == 2) {
            main_blue++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main() {
    read(), solve();
}
#include <iostream>
#include <utility>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
 
ll dp[1002][2004][4];
const ll m = 998244353;
 
 
int main() {
    int n;
    int k;
    cin >> n >> k;
 
    dp[1][1][0] = 1, dp[1][1][3] = 1, dp[1][2][2] = 1, dp[1][2][1] = 1;
    
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 2*n; j++) {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % m; // dp[i - 1][j][0] + dp[i - 1][j - 1][3] + dp[i - 1][j][2] + dp[i - 1][j][1]
            dp[i][j][1] = (dp[i - 1][j][1] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3] + dp[i - 1][j - 2][2])  % m;
            dp[i][j][2] = (dp[i - 1][j][2] + dp[i - 1][j - 1][0] + dp[i - 1][j - 1][3] + dp[i - 1][j - 2][1]) % m;
            dp[i][j][3] = (dp[i - 1][j][3] + dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2]) % m;
        }
    }
 
    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        ans += dp[n][k][i];
        ans = ans %  m;
    }
 
    cout << ans;
}
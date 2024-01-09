#include <iostream>
#include <cmath>
#include <algorithm> 
using namespace std;

int n,k;
long long ns[n];
 
int main() {
    cin >> n >> k;
 
    for(int i = 0; i < n; i++) 
        cin >> ns[i];
 
    int maxYet = ns[n - 1];
 
    for (int b = 0; b < (n - (2*k - n) - 1); b++) {
        if((ns[b] + (ns[(n - (2*k - n) - 1) - b])) > maxYet) {
            maxYet = ns[b] + (ns[(n - (2*k - n) - 1) - b]);
        }
    }
 
    cout << maxYet;
}
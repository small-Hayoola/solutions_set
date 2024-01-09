#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
 
// Restaurant Customers - https://cses.fi/problemset/task/1619

int n;
vector < pair <int, int> > dots;
 
int main() 
{
	cin >> n;
 
	for (int i = 0; i < n; ++i)
	{
		int f,l;
		cin >> f >> l;
 
		dots.push_back(make_pair(f, 1));
		dots.push_back(make_pair(l, -1));
	}
 
	sort(dots.begin(), dots.end());
 
	int amount = 0;
	int out = 0;
 
	for (pair <int, int> c:dots)
	{	
		amount += c.second;
		out = max(out, amount);
	}
 
	cout << out << endl;
}
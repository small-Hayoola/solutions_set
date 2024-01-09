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
 
int t;
 
int main() {
	cin >> t;
 
	while (t--) {
		int n; // dummy garbage
		string s;
		cin >> n;
		cin >> s;
 
		int letters_removed = 0;
 
		while (s.size() > 0 && s[0] == s[s.size() - 1]) {
			s.pop_back();
			letters_removed++;
		}
 
		if (s.size() == 0) {
 
			if (letters_removed < 3) 
				cout << "0" << "\n";
			else if (letters_removed == 3)
				cout << "1" << "\n";
			else 
				cout << (letters_removed / 3) + (letters_removed % 3 != 0) << "\n";
 
		} else {
			int rows = 0;
			
			s.push_back('d'); // dummy garbage trash
			for(int i = 0; i < s.size() - 1; i++) {
				letters_removed++;
				if(s[i] != s[i + 1]) {
					rows += letters_removed / 3;
					letters_removed = 0;
				}
			}
 
			cout << rows << "\n";
		}
 
	}
}
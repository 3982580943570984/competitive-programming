#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string t = s;
		reverse(s.begin(), s.end());
		cout << t << s << endl;
	}
}

#include <iostream>
#include <string>
#include <vector>

#define int long long
using namespace std;

int32_t main () {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		string p; while (p.size() < 60) p += "Yes";
		int pos;
		if (s[0] == 'Y') pos = 0;
		if (s[0] == 'e') pos = 1;
		if (s[0] == 's') pos = 2;
		p = p.substr(pos, s.size());
		cout << (p == s ? "Yes\n" : "No\n");
	}
}

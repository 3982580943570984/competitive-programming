#include <ios>
#include <iostream>
#include <string>

#define int long long
using namespace std;

int32_t main () {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	string s; cin >> s;
	string ans = s;
	auto f1 = s.find('1'); if (f1 == string::npos) { cout << 0 << endl; return 0; }
	auto f0 = s.substr(f1).find('0'); if (f0 == string::npos) { cout << s << endl; return 0; }
	for (int i = 0; i <= f0; ++i) {
		string res = s;
		for (int j = i; j < n; ++j) res[j] |= s[j-i];
		ans = max(ans, res);
	}
	if (ans.find('1') != string::npos)
		cout << ans.substr(ans.find('1')) << endl;
	else
		cout << 0 << endl;
}

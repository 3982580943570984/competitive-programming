#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		vector<int> opened;
		vector<int> closed;
		int marks{0};
		for(int i{0}; i < s.size(); ++i) {
			if(s[i] == '(') { opened.push_back(i); }
			if(s[i] == ')') { closed.push_back(i); }
			if(s[i] == '?') ++marks;
		}

		for(int i{0}; i < min(opened.size(), closed.size()); ++i) {
			s[opened[i]] = ' ';
			s[closed[i]] = ' ';
		}
		s.erase(remove(s.begin(), s.end(), ' '), s.end());

		if(marks/2 == 1 && marks == 2) {
			cout << "YES" << '\n';
			continue;
		}

		int mark_opened = s.size() / 2 - opened.size();
		int mark_closed = s.size() / 2 - closed.size();
		int diff = min(mark_opened, mark_closed);
		mark_opened -= diff;
		mark_closed -= diff;

		if(mark_opened == 0 || mark_closed == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';

	}

	return 0;
}


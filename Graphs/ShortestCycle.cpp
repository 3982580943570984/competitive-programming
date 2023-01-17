#include <iostream>
#include <vector>
#include <map>

#define int long long
using namespace std;

int32_t main () {
	int n; cin >> n;
	vector<int> a(n); for(auto& e : a) cin >> e;
	vector<int> odd, even; for (auto e : a) e & 1 ? odd.push_back(e) : even.push_back(e);
	cout << (3 & 6) << endl;
	cout << (9 & 3) << endl;
	cout << (6 & 28) << endl;
	cout << (9 & 3) << endl;
}

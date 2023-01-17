#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
	int a, b, c; cin >> a >> b >> c;
	vector<int> d{a,b,c};
	sort(d.rbegin(), d.rend());
	cout << d[2] + d[1] - d[0] << endl;
}

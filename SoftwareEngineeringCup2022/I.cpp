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

	int x, n, y, m; cin >> x >> n >> y >> m;

	int first = (x + 1) * n;
	int second = (y + 1) * m;

	if(first <= second) cout << 1 << '\n';
	else cout << 2 << '\n';

	return 0;
}

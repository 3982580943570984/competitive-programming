#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long double h; cin >> h;
	long double l; cin >> l;

	cout << setprecision(15) << (pow(l,2) - pow(h,2)) / (2*h) << endl;

	return 0;
}

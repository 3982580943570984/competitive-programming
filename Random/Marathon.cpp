#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>

#define int long long int

// greatest common divisor
int gcd (int a, int b) { return b ? gcd (b, a % b) : a; }

using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; cin >> t;
	for(int i{0}; i < t; i++) {
		int a; cin >> a;
		int b; cin >> b;
		int c; cin >> c;
		int d; cin >> d;

		int result{0};

		if(b > a) result++;
		if(c > a) result++;
		if(d > a) result++;

		cout << result << endl;		
	}

	return 0;
}

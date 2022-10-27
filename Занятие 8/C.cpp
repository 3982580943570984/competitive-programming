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

	int a, b, n;
	cin >> a >> b >> n;

	int result{1};
	while(n > 0){
		if(result)
			n -= gcd(a, n);
		else 			
			n -= gcd(b, n);

		result = !result;
	}

	cout << result << endl;

	return 0;
}

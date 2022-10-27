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

	int n; cin >> n;
	int max = 0;
	int min = 1000000000;
	for(int i{0}; i < n; i++) { 
		int number; cin >> number;
		if(max <  number) max = number;
		if(min > number) min = number;
	}

	cout << max - min + 1 - n << endl;

	return 0;
}

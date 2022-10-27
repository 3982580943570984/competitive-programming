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

	int k; cin >> k;
	int result{0};
	vector<int> numbers = {1, 1};

	for(int i{1}; i < k; i++){ numbers.push_back(numbers[i] + numbers[i-1]); }
	for(int i{0}; i < k; i++){ result += numbers[i]; }
	
	cout << result << endl;

	return 0;
}

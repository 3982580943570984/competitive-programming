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

	string first; cin >> first;
	string second; cin >> second;

	int steps{0};
	while(!first.empty() && !second.empty()) {
		if(first[0] == 'L' && second[0] != 'L') {
			++steps;
			second.erase(second.begin(), second.begin() + 1);
		}

		if(second[0] == 'L' && first[0] != 'L') {
			++steps;
			first.erase(first.begin(), first.begin() + 1);
		}

		if(first[0] != 'L' && second[0] != 'L' || first[0] == 'L' && second[0] == 'L') {
			++steps;
			first.erase(first.begin(), first.begin() + 1);
			second.erase(second.begin(), second.begin() + 1);
		}
	}

	steps += first.size() + second.size();

	cout << steps << '\n';

	return 0;
}
